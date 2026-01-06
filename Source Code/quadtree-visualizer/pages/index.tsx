'use client'
import React, { Component, createRef, RefObject, ChangeEvent } from 'react'
import ProjectHeader from '../components/project-header'
import SimulationCanvas, { SimulationCanvasProps } from '../components/simulation-canvas'
import ControlBar, { ActionButton, DataConfig, DataSlider, DataToggle, SectionTitle } from '../components/control-bar'
import { QuadTree } from '../utils/quadtree'
import { PhysicsEnvironment } from '../utils/physics'
import { Vector2D } from '../utils/vector2d'
import { updateWith } from '../utils/functions'
import styles from '../styles/Home.module.scss'

interface HomeState extends SimulationCanvasProps {
  count: number
}

/**
 * Main Page which contains the QuadTree Visualizer and Control Bar
 */
export default class Home extends Component<object, HomeState> {
  private simulationCanvasRef: RefObject<SimulationCanvas> = createRef<SimulationCanvas>()

  constructor(props: object) {
    super(props)
    this.state = {
      radius: 5,
      count: 200,
      showFPS: true,
      showQuads: true,
      physicsEnvironment: new PhysicsEnvironment()
    }
    this.spawnRandomBodies = this.spawnRandomBodies.bind(this)
  }

  componentDidMount(): void {
    const radius = Math.ceil(Math.min(window.innerWidth / 200, window.innerHeight / 200))
    this.setState({ radius: radius }, this.spawnRandomBodies)
  }

  spawnRandomBodies(count: number = this.state.count, radius: number = this.state.radius): void {
    const canvas = this.simulationCanvasRef.current
    if (canvas) {
      const speed = 300
      for (let i = 0; i < count; i++) {
        canvas.addBody(
          canvas.randomPointInBounds(radius),
          new Vector2D((Math.random() - 0.5) * speed, (Math.random() - 0.5) * speed),
          radius
        )
      }
    }
  }

  render(): React.ReactElement {
    return (
      <main>
        <div className={styles.simulation_container}>
          <ProjectHeader title="QuadTree Visualizer" year="2022" />
          <SimulationCanvas
            ref={this.simulationCanvasRef}
            showFPS={this.state.showFPS}
            showQuads={this.state.showQuads}
            physicsEnvironment={this.state.physicsEnvironment}
            radius={this.state.radius}
          />
          <ControlBar>
            <SectionTitle title="Collision Speed" />
            <DataSlider
              label="Restitution Coefficient (e)"
              value={this.state.physicsEnvironment.coefficientOfRestitution}
              updateFunc={(value: number): void => {
                updateWith(this.state.physicsEnvironment, { coefficientOfRestitution: value })
                this.setState({ physicsEnvironment: this.state.physicsEnvironment })
              }}
            />
            <SectionTitle title="QuadTree" />
            <DataConfig
              label="Node Capacity"
              value={QuadTree.capacity}
              updateFunc={(e: ChangeEvent<HTMLTextAreaElement | HTMLInputElement>): void => {
                updateWith(QuadTree, { capacity: +e.target.value })
                this.forceUpdate()
              }}
            />
            <DataConfig
              label="Maximum Tree Depth"
              value={QuadTree.maxDepth}
              updateFunc={(e: ChangeEvent<HTMLTextAreaElement | HTMLInputElement>): void => {
                updateWith(QuadTree, { maxDepth: +e.target.value })
                this.forceUpdate()
              }}
            />
            <SectionTitle title="Simulation" />
            <DataConfig
              label="Radius"
              value={this.state.radius}
              updateFunc={(e: ChangeEvent<HTMLTextAreaElement | HTMLInputElement>): void => {
                this.setState({ radius: +e.target.value })
              }}
            />
            <DataConfig
              label="Spawn Count"
              value={this.state.count}
              updateFunc={(e: ChangeEvent<HTMLTextAreaElement | HTMLInputElement>): void => {
                this.setState({ count: +e.target.value })
              }}
            />
            <ActionButton label="Spawn Bodies" onClick={(): void => this.spawnRandomBodies()} />
            <ActionButton label="Clear Bodies" onClick={(): void => { this.simulationCanvasRef.current?.clearBodies() }} />
            <ActionButton label="Random Body" onClick={(): void => this.spawnRandomBodies(1, 20 + Math.random() * 20)} />
            <DataToggle
              label="Show FPS"
              value={this.state.showFPS}
              updateFunc={(_, checked): void => this.setState({ showFPS: checked })}
            />
            <DataToggle
              label="Show Quads"
              value={this.state.showQuads}
              updateFunc={(_, checked): void => this.setState({ showQuads: checked })}
            />
          </ControlBar>
        </div>
      </main>
    )
  }
}
