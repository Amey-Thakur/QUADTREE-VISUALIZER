import React from 'react'
import styles from './project-header.module.scss'

interface ProjectHeaderProps {
  title: string
  year: string
}

function ProjectHeader(props: ProjectHeaderProps): React.ReactElement {
  return (
    <div className={styles.header_container}>
      <div>
        <div id={styles.title}>{props.title}</div>
        <div>Presented as part of the BE Major-Project @ Terna Engineering College</div>
        <div>
          Project Authors: Amey Thakur, Hasan Rizvi, Mega Satish and Ajay Davare
          (Group: Phi-CS-73, Batch of: {props.year})
        </div>
      </div>
    </div>
  )
}

export default ProjectHeader