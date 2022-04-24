import { Component, createRef, RefObject } from 'react'
import ProjectHeader from '../components/project-header'
import SimulationCanvas, { SimulationCanvasProps } from '../components/simulation-canvas'
import ControlBar, { ActionButton, DataConfig, DataSlider, DataToggle, SectionTitle } from '../components/control-bar'
import { QuadTree } from '../utils/quadtree'
import { PhysicsEnvironment } from '../utils/physics'
import { Vector2D } from '../utils/vector2d'
import { updateWith } from '../utils/functions'
import styles from '../styles/Home.module.scss'

class SimulationFields implements SimulationCanvasProps {
  radius = 5
  count = 200
  showFPS = true
  showQuads = true
  physicsEnvironment = new PhysicsEnvironment
}

/**
 * Main Page which contains the QuadTree Visualizer and Control Bar
 */
export default class Home extends Component<unknown, SimulationFields> {
  private simulationCanvasRef: RefObject<SimulationCanvas> = createRef()
  constructor(props: unknown) {
    super(props)
    this.state = new SimulationFields
    this.spawnRandomBodies = this.spawnRandomBodies.bind(this)
  }

  componentDidMount(): void {
    // calculate a radius that is relatively the same ratio for all windows
    const radius = Math.ceil(Math.min(window.innerWidth / 200, window.innerHeight / 200))
    // set initial variables
    this.setState({ radius: radius }, this.spawnRandomBodies)
  }

  /**
   * Spawn a number of Bodies with random velocity
   * based on current simulation variables
   */
  spawnRandomBodies(count: number = this.state.count, radius: number = this.state.radius): void {
    if (this.simulationCanvasRef.current) {
      const speed = 300
      for (let i = 0; i < count; i++)
        this.simulationCanvasRef.current.addBody(
          this.simulationCanvasRef.current.randomPointInBounds(radius),
          new Vector2D((Math.random() - 0.5) * speed, (Math.random() - 0.5) * speed),
          radius,
        )
    }
  }

  render(): JSX.Element {
    return (
      <main>
        <div className={styles.simulation_container}>
          <ProjectHeader title="QuadTree Visualizer" year="2022" />
          <SimulationCanvas ref={this.simulationCanvasRef}
            showFPS={this.state.showFPS}
            showQuads={this.state.showQuads}
            physicsEnvironment={this.state.physicsEnvironment}
            radius={this.state.radius} />
          <ControlBar>
            <SectionTitle title="Collision Speed" />
            <DataSlider label="Restitution Coefficient (e)" value={this.state.physicsEnvironment.coefficientOfRestitution}
              updateFunc={(value: number) => {
                updateWith(this.state.physicsEnvironment, { coefficientOfRestitution: value })
                this.setState({ physicsEnvironment: this.state.physicsEnvironment })
              }} />
            <SectionTitle title="QuadTree" />
            <DataConfig label="Node Capacity" value={QuadTree.capacity}
              updateFunc={(value) => { updateWith(QuadTree, { capacity: +value.target.value }); this.forceUpdate() }} />
            <DataConfig label="Maxmimum Tree Depth" value={QuadTree.maxDepth}
              updateFunc={(value) => { updateWith(QuadTree, { maxDepth: +value.target.value }); this.forceUpdate() }} />
            <SectionTitle title="Simulation" />
            <DataConfig label="Radius" value={this.state.radius}
              updateFunc={(value) => this.setState({ radius: +value.target.value })} />
            <DataConfig label="Spawn Count" value={this.state.count}
              updateFunc={(value) => this.setState({ count: +value.target.value })} />
            <ActionButton label="Spawn Bodies"
              onClick={() => this.spawnRandomBodies()} />
            <ActionButton label="Clear Bodies"
              onClick={() => this.simulationCanvasRef.current?.clearBodies()} />
            <ActionButton label="Random Body"
              onClick={() => this.spawnRandomBodies(1, 20 + Math.random() * 20)} />
            <DataToggle label="Show FPS" value={this.state.showFPS}
              updateFunc={(_, checked) => this.setState({ showFPS: checked })} />
            <DataToggle label="Show Quads" value={this.state.showQuads}
              updateFunc={(_, checked) => this.setState({ showQuads: checked })} />
          </ControlBar>
        </div>
      </main>
    )
  }
}
