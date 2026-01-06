'use client'
import React from 'react'
import { createTheme, ThemeProvider } from '@mui/material/styles'
import CssBaseline from '@mui/material/CssBaseline'
import type { AppProps } from 'next/app'
import Head from 'next/head'
import '../styles/globals.scss'
import styles from '../styles/theme.module.scss'

const theme = createTheme({
  typography: {
    fontFamily: '\'Play\', sans-serif',
    allVariants: {
      fontFamily: '\'Play\', sans-serif',
    },
  },
  palette: {
    primary: {
      main: styles.color1 || '#000000'
    },
    secondary: {
      main: styles.color1 || '#000000'
    },
    text: {
      primary: styles.color1 || '#000000',
      secondary: styles.color1 || '#000000'
    }
  },
  components: {
    MuiCssBaseline: {
      styleOverrides: {
        '*': {
          fontFamily: '\'Play\', sans-serif !important',
        },
        body: {
          fontFamily: '\'Play\', sans-serif',
        },
      },
    },
    MuiButton: {
      styleOverrides: {
        root: {
          fontFamily: '\'Play\', sans-serif',
        },
      },
    },
    MuiTextField: {
      styleOverrides: {
        root: {
          fontFamily: '\'Play\', sans-serif',
        },
      },
    },
    MuiInputBase: {
      styleOverrides: {
        root: {
          fontFamily: '\'Play\', sans-serif',
        },
      },
    },
    MuiFormControlLabel: {
      styleOverrides: {
        label: {
          fontFamily: '\'Play\', sans-serif',
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
        <link rel='icon' href={`${basePath}/favicon.ico`} />
        <meta name='viewport' content='width=device-width, initial-scale=1' />
        <meta name='description' content='Interactive QuadTree spatial partitioning visualizer with physics simulation' />
      </Head>
      <Component {...pageProps} />
    </ThemeProvider>
  )
}

export default MyApp
