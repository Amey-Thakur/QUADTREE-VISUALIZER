/**
 * Author: Amey Thakur
 * GitHub: https://github.com/Amey-Thakur
 *
 * Author: Mega Satish
 * GitHub: https://github.com/msatmod
 *
 * Author: Hasan Rizvi
 * GitHub: https://github.com/rizvihasan
 *
 * Project: QUADTREE-VISUALIZER
 * Group: Phi-CS-73
 * Batch: 2022
 * Repo: https://github.com/Amey-Thakur/QUADTREE-VISUALIZER
 * Date: 2022-01-19
 * License: MIT
 *
 * Developed as part of the BE Major-Project @ Terna Engineering College.
 *
 * Implements the `ControlBar` UI component, providing interactive controls for real-time
 * simulation parameter tuning. Features React-based sliders, toggles, and input fields
 * for modifying physics constraints (Restitution), QuadTree properties (Capacity, Depth),
 * and simulation inputs (Radius, Count), offering a dynamic user experience.
 */

'use client'
import React, { ChangeEvent, Component, ReactNode } from 'react'

import Button from '@mui/material/Button'
import Checkbox from '@mui/material/Checkbox'
import FormControlLabel from '@mui/material/FormControlLabel'
import Slider from '@mui/material/Slider'
import TextField from '@mui/material/TextField'
import EditIcon from '@mui/icons-material/Edit'
import NavigateBeforeIcon from '@mui/icons-material/NavigateBefore'

import styles from './control-bar.module.scss'

interface ControlBarProps {
  children?: ReactNode
}

interface ControlBarState {
  showing: boolean
}

export default class ControlBar extends Component<ControlBarProps, ControlBarState> {
  constructor(props: ControlBarProps) {
    super(props)
    this.state = { showing: false }
    this.handleClick = this.handleClick.bind(this)
  }

  public setShowing(show: boolean): void {
    this.setState({ showing: show })
  }

  handleClick(): void {
    this.setState({ showing: !this.state.showing })
  }

  render(): React.ReactElement {
    return (
      <div className={styles.control_bar}>
        <div
          className={styles.minimized}
          style={{ transform: `translateX(${this.state.showing ? -100 : 0}%)` }}
          onClick={this.handleClick}
        >
          <EditIcon style={{ fontSize: 35 }} />
        </div>
        <div
          className={styles.panel}
          style={{ transform: `translateX(${this.state.showing ? 0 : -100}%)` }}
        >
          <ControlNav hideFunc={this.handleClick} />
          <div style={{ margin: 'auto', height: 2, width: '90%', backgroundColor: styles.color2 || '#000000' }} />
          <div id={styles.options}>
            {this.props.children}
          </div>
          <UIInfo />
        </div>
      </div>
    )
  }
}

function ControlNav(props: { hideFunc: () => void }): React.ReactElement {
  return (
    <div id={styles.top_control}>
      <NavigateBeforeIcon style={{ fontSize: 50 }} onClick={props.hideFunc} />
      <p>SETTINGS</p>
    </div>
  )
}

function UIInfo(): React.ReactElement {
  return (
    <div style={{ textAlign: 'center', fontSize: '0.8rem' }}>
      <i>Click and Drag to Launch a New Body</i>
    </div>
  )
}

export function SectionTitle(props: { title: string }): React.ReactElement {
  return <div className={styles.section_header}>{props.title.toUpperCase()}</div>
}

export function DataSlider(props: {
  value: number
  updateFunc: (value: number) => void
  label: string
}): React.ReactElement {
  return (
    <div>
      <div className={styles.data_title}>
        Restitution Constant<br /><b>{props.value}</b>
      </div>
      <Slider
        style={{ width: '80%' }}
        value={props.value}
        onChange={(_, value: number | number[]): void => {
          props.updateFunc(typeof value === 'number' ? value : 0)
        }}
        step={0.01}
        min={0}
        max={1}
      />
    </div>
  )
}

export function ActionButton(props: { onClick: () => void; label: string }): React.ReactElement {
  return (
    <Button onClick={props.onClick} size="medium">
      {props.label}
    </Button>
  )
}

export function DataConfig<T>(props: {
  value: T
  label: string
  updateFunc: (value: ChangeEvent<HTMLTextAreaElement | HTMLInputElement>) => void
}): React.ReactElement {
  return (
    <form autoComplete="off">
      <TextField
        onChange={props.updateFunc}
        value={String(props.value)}
        label={props.label}
        variant="filled"
        inputMode="numeric"
      />
    </form>
  )
}

export function DataToggle(props: {
  value: boolean | undefined
  label: string
  updateFunc: (event: ChangeEvent<HTMLInputElement>, checked: boolean) => void
}): React.ReactElement {
  return (
    <FormControlLabel
      control={
        <Checkbox
          checked={props.value === undefined ? true : props.value}
          onChange={props.updateFunc}
        />
      }
      label={props.label}
      style={{ marginLeft: 10, marginRight: 'auto' }}
    />
  )
}
