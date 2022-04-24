import styles from './project-header.module.scss'

const ProjectHeader = (props: { title: string, year: string }): JSX.Element => (
  <div className={styles.header_container}>
    <div>
      <div id={styles.title}>{props.title}</div>
      <div>Presented as part of the BE Major-Project @ Terna Engineering College</div>
      <div>Project Authors: Amey Thakur, Hasan Rizvi, Mega Satish and Ajay Davare (Group: Phi-CS-73, Batch of: {props.year})</div>
    </div>
  </div>
)
export default ProjectHeader