import { PhysicsBody, PhysicsEnvironment, compute2DCollision } from './physics'
import { QuadObject } from './quadtree'
import { Rect } from './shapes'
import { Vector2D } from './vector2d'

type BoundType = 'TOP' | 'LEFT' | 'BOTTOM' | 'RIGHT' | 'INSIDE'
export class CircleBody implements QuadObject, PhysicsBody {
  mass: number
  constructor(
    public position: Vector2D,
    public velocity: Vector2D,
    public radius: number,
    public physicsEnv: PhysicsEnvironment) {
    this.mass = this.radius // mass proportionate to size
  }

  tick(delta: number): void {
    this.position = this.position.plus(this.velocity.scale(delta))
  }

  collide(other: CircleBody): void {
    const collisionVector = this.position.vectorTo(other.position) // from this -> other
    const collisionDistance = this.radius + other.radius
    if (collisionVector.sqrMagnitude < collisionDistance * collisionDistance) {
      // remove the touching distance by pushing the pushing body backwards
      const thisToOtherVec = collisionVector.normalized()
      const otherToThisVec = thisToOtherVec.reversed()
      const thisIsFacingCollision = this.velocity.cosineAngleBetween(thisToOtherVec) > 0
      const otherIsFacingCollision = other.velocity.cosineAngleBetween(otherToThisVec) > 0
      if (thisIsFacingCollision)
        this.position = other.position.plus(otherToThisVec.scale(collisionDistance))
      else if (otherIsFacingCollision)
        other.position = this.position.plus(thisToOtherVec.scale(collisionDistance))
      // compute collisions
      const resultingVelocities = compute2DCollision(this, other, this.physicsEnv, thisToOtherVec)
      this.velocity = resultingVelocities.first
      other.velocity = resultingVelocities.second
    }
  }

  collideBounds(boundRect: Rect): void {
    switch (this.exitingBounds(boundRect)) {
      case 'TOP':
        this.position.y = this.radius
        this.velocity.y *= -1
        break
      case 'BOTTOM':
        this.position.y = boundRect.y + boundRect.h - this.radius
        this.velocity.y *= -1
        break
      case 'LEFT':
        this.position.x = this.radius
        this.velocity.x *= -1
        break
      case 'RIGHT':
        this.position.x = boundRect.x + boundRect.w - this.radius
        this.velocity.x *= -1
        break
      default: break
    }
  }

  exitingBounds(rect: Rect): BoundType {
    if (this.position.x + this.radius > rect.x + rect.w) return 'RIGHT'
    if (this.position.x - this.radius < rect.x) return 'LEFT'
    if (this.position.y + this.radius > rect.y + rect.h) return 'BOTTOM'
    if (this.position.y - this.radius < rect.y) return 'TOP'
    return 'INSIDE'
  }

  insideRect(rect: Rect): boolean {
    return this.position.x + this.radius <= rect.x + rect.w
      && this.position.x - this.radius >= rect.x
      && this.position.y + this.radius <= rect.y + rect.h
      && this.position.y - this.radius >= rect.y
  }
}