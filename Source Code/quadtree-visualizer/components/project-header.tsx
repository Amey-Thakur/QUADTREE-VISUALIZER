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
          Project Authors:{' '}
          <a href='https://github.com/Amey-Thakur' target='_blank' rel='noopener noreferrer' className={styles.author_link}>
            Amey Thakur
          </a>
          ,{' '}
          <a href='https://github.com/rizvihasan' target='_blank' rel='noopener noreferrer' className={styles.author_link}>
            Hasan Rizvi
          </a>
          ,{' '}
          <a href='https://github.com/msatmod' target='_blank' rel='noopener noreferrer' className={styles.author_link}>
            Mega Satish
          </a>
          {' '}and Ajay Davare (Group: Phi-CS-73, Batch of: {props.year})
        </div>
      </div>
    </div>
  )
}

export default ProjectHeader