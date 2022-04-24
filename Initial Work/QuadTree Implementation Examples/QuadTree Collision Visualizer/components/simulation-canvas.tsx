import { Component, createRef, RefObject, MouseEvent } from 'react'
import styles from './simulation-canvas.module.scss'

import { QuadNode, QuadTree } from '../utils/quadtree'
import { Rect } from '../utils/shapes'
import { CircleBody } from '../utils/circlebody'
import { Vector2D } from '../utils/vector2d'
import { PhysicsEnvironment } from '../utils/physics'

const time = () => new Date().getTime()

export interface SimulationCanvasProps { radius: number, showFPS: boolean, showQuads: boolean, physicsEnvironment: PhysicsEnvironment }
export default class SimulationCanvas extends Component<SimulationCanvasProps> {
  private timestamp = time()
  private dragVector = { start: new Vector2D, end: new Vector2D, isDragging: false }
  private stopLoop: boolean
  private quadTree!: QuadTree
  private canvasBounds!: Rect
  private bodies = new Array<CircleBody>()
  private canvasRef: RefObject<HTMLCanvasElement> = createRef()
  private canvasDivRef: RefObject<HTMLDivElement> = createRef()
  constructor(props: SimulationCanvasProps) {
    super(props)
    this.stopLoop = false
    // bind for context in animation callback
    this.renderLoop = this.renderLoop.bind(this)
    this.mouseDown = this.mouseDown.bind(this)
    this.mouseUp = this.mouseUp.bind(this)
    this.mouseDrag = this.mouseDrag.bind(this)
  }

  /**
   * Generates a random point on the canvas where a body can spawn
   */
  public randomPointInBounds(radius: number = this.props.radius): Vector2D {
    return new Vector2D(
      radius + (this.canvasBounds.w - radius) * Math.random(),
      radius + (this.canvasBounds.h - radius) * Math.random()
    )
  }

  /**
   * Clear all bodies from the simulation
   */
  public clearBodies(): void {
    this.bodies = new Array<CircleBody>()
    this.quadTree.quadObjects = this.bodies
  }

  /**
   * Spawn a body into the simulation
   */
  public addBody(position: Vector2D, velocity: Vector2D, radius: number): void {
    this.quadTree.insert(new CircleBody(position, velocity, radius, this.props.physicsEnvironment))
  }

  componentWillUnmount(): void {
    this.stopLoop = true
  }

  componentDidMount(): void {
    window.onresize = () => this.configureBounds()
    this.configureBounds()
    this.renderLoop()
  }

  /**
   * Retrieves Bounds of the Canvas in order to initialize QuadTree Bounds
   */
  configureBounds(): void {
    if (this.canvasDivRef?.current) {
      if (this.canvasRef.current) {
        const context = this.canvasRef.current.getContext('2d')
        if (context) {
          const dimensions = Math.min(this.canvasDivRef.current.clientWidth, this.canvasDivRef.current.clientHeight)
          context.canvas.width = dimensions
          context.canvas.height = dimensions
          this.canvasBounds = new Rect(0, 0, this.canvasRef.current?.width, this.canvasRef.current?.height)
          this.quadTree = new QuadTree(this.canvasBounds, this.bodies)
        }
      }
    }
  }

  // Update Graphics
  renderSimulation(canvasContext: CanvasRenderingContext2D): void {
    canvasContext.fillStyle = styles.color1
    canvasContext.fillRect(0, 0, this.canvasBounds.w, this.canvasBounds.h)
    canvasContext.strokeStyle = styles.color4
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


    function showQuadTrees(quad: QuadNode) {
      canvasContext.strokeRect(quad.bounds.x, quad.bounds.y, quad.bounds.w, quad.bounds.h)
      quad.leaves?.forEach((leaf: QuadNode) => showQuadTrees(leaf))
    }
    if (this.props.showQuads) {
      canvasContext.strokeStyle = styles.color3
      showQuadTrees(this.quadTree.quadRoot)
    }
  }

  // Update Physics
  updateSimulation(delta: number): void {
    this.bodies.forEach((particle: CircleBody) => particle.tick(delta))
    this.quadTree.process(this.quadTreeProcedure())
    this.bodies.forEach((particle: CircleBody) => particle.collideBounds(this.canvasBounds))
  }

  /**
   * The procedure for each node on a QuadTree after insertion is finished
   */
  quadTreeProcedure(): ((quadNode: QuadNode) => void) {
    // currently does collisions
    return function processCollisions(quadNode: QuadNode) {
      const collisionObject = quadNode.quadObjects as CircleBody[]
      // process current level collisions
      for (let i = 0; i < collisionObject.length; i++)
        for (let j = i + 1; j < collisionObject.length; j++)
          collisionObject[i].collide(collisionObject[j])

      // process rescursive collisions
      const processLeafCollisions = (leaves: QuadNode[] | null): void => {
        leaves?.forEach((leaf: QuadNode) => {
          collisionObject.forEach((object: CircleBody) => {
            const leafCollisionObjects = leaf.quadObjects as CircleBody[]
            leafCollisionObjects.forEach((leafObject: CircleBody) =>
              object.collide(leafObject)
            )
          })
          // recurse
          processLeafCollisions(leaf.leaves)
        })
      }
      // call on current leaves
      processLeafCollisions(quadNode.leaves)

      // recurse on following quad nodes
      quadNode.leaves?.forEach((leaf: QuadNode) => processCollisions(leaf))
    }
  }

  // Logic Loop
  renderLoop(): void {
    if (this.stopLoop)
      return

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
        context.font = '25px Arial'
        context.fillStyle = styles.color4
        context.fillText('FPS: ' + fps, 10, 30)
        context.restore()
      }
    }

    // request another frame to tick
    requestAnimationFrame(this.renderLoop)
  }

  mouseDown(e: MouseEvent): void {
    if (this.canvasRef.current) {
      this.dragVector.start = this.dragVector.end = new Vector2D(e.clientX - this.canvasRef.current?.offsetLeft, e.clientY - this.canvasRef.current?.offsetTop)
      this.dragVector.isDragging = true
    }
  }

  mouseDrag(e: MouseEvent): void {
    if (this.dragVector.isDragging && this.canvasRef.current)
      this.dragVector.end = new Vector2D(e.clientX - this.canvasRef.current?.offsetLeft, e.clientY - this.canvasRef.current?.offsetTop)
  }

  mouseUp(): void {
    this.addBody(this.dragVector.start, this.dragVector.start.vectorTo(this.dragVector.end), this.props.radius)
    this.dragVector.isDragging = false
  }

  render(): JSX.Element {
    return (
      <div className={styles.canvas_container}>
        <div ref={this.canvasDivRef} className={styles.canvas_wrapper}>
          <canvas ref={this.canvasRef} onMouseDown={this.mouseDown} onMouseUp={this.mouseUp} onMouseMove={this.mouseDrag} />
        </div>
      </div>
    )
  }
}