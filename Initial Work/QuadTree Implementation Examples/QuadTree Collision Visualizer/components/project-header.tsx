import styles from './project-header.module.scss'

const ProjectHeader = (props: { title: string, year: string }): JSX.Element => (
  <div className={styles.header_container}>
    <div>
      <div id={styles.title}>{props.title}</div>
      <div>Nicholas Baker {props.year}</div>
    </div>
  </div>
)
export default ProjectHeader