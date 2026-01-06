'use client'
import React from 'react'
import { createTheme, ThemeProvider } from '@mui/material/styles'
import CssBaseline from '@mui/material/CssBaseline'
import { AppProps } from 'next/app'
import Head from 'next/head'
import '../styles/globals.scss'
import styles from '../styles/theme.module.scss'

const theme = createTheme({
  typography: {
    fontFamily: "'Play', sans-serif",
  },
  palette: {
    primary: {
      main: styles.color1 || '#1a1a2e'
    },
    secondary: {
      main: styles.color1 || '#1a1a2e'
    },
    text: {
      primary: styles.color1 || '#1a1a2e',
      secondary: styles.color1 || '#1a1a2e'
    }
  },
  components: {
    MuiCssBaseline: {
      styleOverrides: {
        body: {
          fontFamily: "'Play', sans-serif",
        },
      },
    },
  },
})

const basePath = process.env.NODE_ENV === 'production' ? '/QUADTREE-VISUALIZER' : ''

function MyApp({ Component, pageProps }: AppProps): React.ReactElement {
  return (
    <ThemeProvider theme={theme}>
      <CssBaseline />
      <Head>
        <title>QuadTree Visualizer</title>
        <link rel="icon" href={`${basePath}/favicon.ico`} />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
      </Head>
      <Component {...pageProps} />
    </ThemeProvider>
  )
}

export default MyApp
