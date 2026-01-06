'use client'
import React, { Component, createRef, RefObject, MouseEvent as ReactMouseEvent } from 'react'
import styles from './simulation-canvas.module.scss'

import { QuadNode, QuadTree } from '../utils/quadtree'
import { Rect } from '../utils/shapes'
import { CircleBody } from '../utils/circlebody'
import { Vector2D } from '../utils/vector2d'
import { PhysicsEnvironment } from '../utils/physics'

const time = (): number => new Date().getTime()

export interface SimulationCanvasProps {
  radius: number
  showFPS: boolean
  showQuads: boolean
  physicsEnvironment: PhysicsEnvironment
}

interface SimulationCanvasState {
  initialized: boolean
}

export default class SimulationCanvas extends Component<SimulationCanvasProps, SimulationCanvasState> {
  private timestamp = time()
  private dragVector = { start: new Vector2D(), end: new Vector2D(), isDragging: false }
  private stopLoop = false
  private quadTree!: QuadTree
  private canvasBounds!: Rect
  private bodies: CircleBody[] = []
  private canvasRef: RefObject<HTMLCanvasElement> = createRef<HTMLCanvasElement>()
  private canvasDivRef: RefObject<HTMLDivElement> = createRef<HTMLDivElement>()

  constructor(props: SimulationCanvasProps) {
    super(props)
    this.state = { initialized: false }
    this.renderLoop = this.renderLoop.bind(this)
    this.mouseDown = this.mouseDown.bind(this)
    this.mouseUp = this.mouseUp.bind(this)
    this.mouseDrag = this.mouseDrag.bind(this)
  }

  public randomPointInBounds(radius: number = this.props.radius): Vector2D {
    return new Vector2D(
      radius + (this.canvasBounds.w - radius) * Math.random(),
      radius + (this.canvasBounds.h - radius) * Math.random()
    )
  }

  public cornerPointWithSpread(radius: number = this.props.radius, spread: number = 50): Vector2D {
    // Spawn from top-left corner with some random spread
    return new Vector2D(
      radius + Math.random() * spread,
      radius + Math.random() * spread
    )
  }

  public clearBodies(): void {
    this.bodies = []
    this.quadTree.quadObjects = this.bodies
  }

  public addBody(position: Vector2D, velocity: Vector2D, radius: number): void {
    this.quadTree.insert(new CircleBody(position, velocity, radius, this.props.physicsEnvironment))
  }

  componentWillUnmount(): void {
    this.stopLoop = true
  }

  componentDidMount(): void {
    window.onresize = (): void => this.configureBounds()
    this.configureBounds()
    this.renderLoop()
  }

  configureBounds(): void {
    const canvasDiv = this.canvasDivRef.current
    const canvas = this.canvasRef.current
    if (canvasDiv && canvas) {
      const context = canvas.getContext('2d')
      if (context) {
        const dimensions = Math.min(canvasDiv.clientWidth, canvasDiv.clientHeight)
        context.canvas.width = dimensions
        context.canvas.height = dimensions
        this.canvasBounds = new Rect(0, 0, canvas.width, canvas.height)
        this.quadTree = new QuadTree(this.canvasBounds, this.bodies)
      }
    }
  }

  renderSimulation(canvasContext: CanvasRenderingContext2D): void {
    canvasContext.fillStyle = styles.color1 || '#000000'
    canvasContext.fillRect(0, 0, this.canvasBounds.w, this.canvasBounds.h)
    canvasContext.strokeStyle = styles.color4 || '#ffffff'
    this.bodies.forEach((particle: CircleBody) => {
      canvasContext.beginPath()
      canvasContext.arc(particle.position.x, particle.position.y, particle.radius, 0, 2 * Math.PI)
      canvasContext.stroke()
    })
    if (this.dragVector.isDragging) {
      canvasContext.beginPath()
      canvasContext.moveTo(this.dragVector.start.x, this.dragVector.start.y)
      canvasContext.lineTo(this.dragVector.end.x, this.dragVector.end.y)
      canvasContext.stroke()
    }

    const showQuadTrees = (quad: QuadNode): void => {
      canvasContext.strokeRect(quad.bounds.x, quad.bounds.y, quad.bounds.w, quad.bounds.h)
      quad.leaves?.forEach((leaf: QuadNode) => showQuadTrees(leaf))
    }
    if (this.props.showQuads) {
      canvasContext.strokeStyle = styles.color3 || '#ffffff'
      showQuadTrees(this.quadTree.quadRoot)
    }
  }

  updateSimulation(delta: number): void {
    this.bodies.forEach((particle: CircleBody) => particle.tick(delta))
    this.quadTree.process(this.quadTreeProcedure())
    this.bodies.forEach((particle: CircleBody) => particle.collideBounds(this.canvasBounds))
  }

  quadTreeProcedure(): (quadNode: QuadNode) => void {
    return function processCollisions(quadNode: QuadNode): void {
      const collisionObject = quadNode.quadObjects as CircleBody[]
      for (let i = 0; i < collisionObject.length; i++) {
        for (let j = i + 1; j < collisionObject.length; j++) {
          collisionObject[i].collide(collisionObject[j])
        }
      }

      const processLeafCollisions = (leaves: QuadNode[] | null): void => {
        leaves?.forEach((leaf: QuadNode) => {
          collisionObject.forEach((object: CircleBody) => {
            const leafCollisionObjects = leaf.quadObjects as CircleBody[]
            leafCollisionObjects.forEach((leafObject: CircleBody) =>
              object.collide(leafObject)
            )
          })
          processLeafCollisions(leaf.leaves)
        })
      }
      processLeafCollisions(quadNode.leaves)
      quadNode.leaves?.forEach((leaf: QuadNode) => processCollisions(leaf))
    }
  }

  renderLoop(): void {
    if (this.stopLoop) return

    const newtime = time()
    const fps = Math.round(1000 / (newtime - this.timestamp))
    this.timestamp = newtime

    this.updateSimulation(1 / fps)

    const canvas = this.canvasRef.current
    const context = canvas?.getContext('2d')

    if (context) {
      this.renderSimulation(context)

      if (this.props.showFPS) {
        context.save()
        context.font = '25px \'Play\', sans-serif'
        context.fillStyle = styles.color4 || '#ffffff'
        context.fillText('FPS: ' + fps, 10, 30)
        context.restore()
      }
    }

    requestAnimationFrame(this.renderLoop)
  }

  mouseDown(e: ReactMouseEvent<HTMLCanvasElement>): void {
    const canvas = this.canvasRef.current
    if (canvas) {
      this.dragVector.start = this.dragVector.end = new Vector2D(
        e.clientX - canvas.offsetLeft,
        e.clientY - canvas.offsetTop
      )
      this.dragVector.isDragging = true
    }
  }

  mouseDrag(e: ReactMouseEvent<HTMLCanvasElement>): void {
    const canvas = this.canvasRef.current
    if (this.dragVector.isDragging && canvas) {
      this.dragVector.end = new Vector2D(
        e.clientX - canvas.offsetLeft,
        e.clientY - canvas.offsetTop
      )
    }
  }

  mouseUp(): void {
    this.addBody(this.dragVector.start, this.dragVector.start.vectorTo(this.dragVector.end), this.props.radius)
    this.dragVector.isDragging = false
  }

  render(): React.ReactElement {
    return (
      <div className={styles.canvas_container}>
        <div ref={this.canvasDivRef} className={styles.canvas_wrapper}>
          <canvas
            ref={this.canvasRef}
            onMouseDown={this.mouseDown}
            onMouseUp={this.mouseUp}
            onMouseMove={this.mouseDrag}
          />
        </div>
      </div>
    )
  }
}