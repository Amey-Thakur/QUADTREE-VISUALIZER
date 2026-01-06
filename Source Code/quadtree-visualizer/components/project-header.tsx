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
 * Renders the project header component, displaying key metadata including the project title,
 * academic cohort details (Group Phi-CS-73), and links to the authors' profiles.
 * Serves as the primary attribution banner for the visualization interface.
 */

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
        <a
          href='https://github.com/Amey-Thakur/QUADTREE-VISUALIZER'
          target='_blank'
          rel='noopener noreferrer'
          id={styles.title}
          className={styles.author_link}
        >
          {props.title}
        </a>
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