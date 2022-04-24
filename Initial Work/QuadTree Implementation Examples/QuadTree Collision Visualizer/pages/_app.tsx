import { createMuiTheme, ThemeProvider } from '@material-ui/core'
import { AppProps } from 'next/app'
import Head from 'next/head'
import '../styles/globals.scss'
import styles from '../styles/theme.module.scss'

const theme = createMuiTheme({
  palette: {
    primary: {
      main: styles.color1
    },
    secondary: {
      main: styles.color1
    },
    text: {
      primary: styles.color1,
      secondary: styles.color1
    }
  }
})

function MyApp({ Component, pageProps }: AppProps): JSX.Element {
  return (
    <ThemeProvider theme={theme}>
      <Head>
        <title>Quadtree Visualizer</title>
        <link rel="icon" href="/favicon.ico" />
      </Head>
      <Component {...pageProps} />
    </ThemeProvider>
  )
}

export default MyApp
