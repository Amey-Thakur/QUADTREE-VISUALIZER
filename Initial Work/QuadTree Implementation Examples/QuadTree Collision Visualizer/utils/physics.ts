import { Vector2D } from './vector2d'

/**
 * Set of Requirements for a Physics Environment
 */
export class PhysicsEnvironment {
  public coefficientOfRestitution = 0.8
}

/**
 * Minimum requirements of a body to calculate physics based processes
 * - omitting acceleration for now
 */
export interface PhysicsBody {
  position: Vector2D,
  velocity: Vector2D,
  mass: number
}

/**
 * Computes a collision for the environment
 * first - the resulting velocity vector for body1
 * second - the resulting velocity vector for body2
 * @param first the first physics body 
 * @param second the second physics body
 */
export function compute2DCollision(
  first: PhysicsBody,
  second: PhysicsBody,
  environment: PhysicsEnvironment,
  unitNormalofCollision?: Vector2D): { first: Vector2D, second: Vector2D } {
  /* 1D Collision
   * v = final velocity vector
   * u = initial velocty vector
   * m = mass of body
   * p = momentum of body
   * Cr = coefficient of Restitution
   * 
   *       (Cr)(m2)(u2 - u1) + (m1)(v1) + (m2)(v2)     (Cr)(m2)(u2 - u1) + p1 + p2
   * v1 = ————————————————————————————————————————— = —————————————————————————————
   *                      m1 + m2                                m1 + m2
   * 
   *       (Cr)(m1)(u1 - u2) + (m1)(v1) + (m2)(v2)      (Cr)(m1)(u1 - u2) + p1 + p2
   * v2 = ————————————————————————————————————————— =  —————————————————————————————
   *                      m1 + m2                                m1 + m2
   */
  // used in all computations
  const jointMass = first.mass + second.mass
  // unit vectors of critical axis
  const unitNormalVec = unitNormalofCollision || first.position.vectorTo(second.position).normalized()
  const unitTangentVec = new Vector2D(-unitNormalVec.y, unitNormalVec.x)
  // going to calculate collisions in the normal plane (apply normal 1D collision algo)
  const firstNormalVel = first.velocity.dot(unitNormalVec)
  const secondNormalVel = second.velocity.dot(unitNormalVec)
  // p_total = m_1 * v_1 + m_2 * v_2 
  const totalNormalMomentum = first.mass * firstNormalVel + second.mass * secondNormalVel
  // v1_norm = v1 * unit_norm
  const firstNormalVec = unitNormalVec.scale(
    (environment.coefficientOfRestitution * second.mass * (secondNormalVel - firstNormalVel) + totalNormalMomentum) / jointMass
  )
  // v2_norm = v2 * unit_norm
  const secondNormalVec = unitNormalVec.scale(
    (environment.coefficientOfRestitution * first.mass * (firstNormalVel - secondNormalVel) + totalNormalMomentum) / jointMass
  )
  // tangent plane components stay the same, just in the tangent plane
  // v_tangent = v * unit_tangent
  const firstTangentVec = unitTangentVec.scale(first.velocity.dot(unitTangentVec))
  const secondTangentVec = unitTangentVec.scale(second.velocity.dot(unitTangentVec))

  // return composition of normal and tangent components
  // vec = vec_norm + vec_tangent
  return {
    first: firstNormalVec.plus(firstTangentVec),
    second: secondNormalVec.plus(secondTangentVec)
  }
}
