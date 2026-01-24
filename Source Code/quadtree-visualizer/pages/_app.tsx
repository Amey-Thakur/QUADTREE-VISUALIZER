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
 * Date: 2022-04-25
 * License: MIT
 *
 * Developed as part of the BE Major-Project @ Terna Engineering College.
 *
 * Serves as the global application wrapper for the Next.js project.
 * Responsible for initializing the Material-UI theme context (`ThemeProvider`),
 * applying global CSS baselines (`CssBaseline`), and injecting head metadata
 * (favicon, viewport settings, SEO descriptions) consistent across all views.
 */

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
  const [loading, setLoading] = React.useState(true)

  React.useEffect(() => {
    // Hide loading screen after page load
    const timer = setTimeout(() => {
      setLoading(false)
    }, 3200)

    return () => clearTimeout(timer)
  }, [])

  return (
    <ThemeProvider theme={theme}>
      <CssBaseline />
      <Head>
        <title>QuadTree Visualizer</title>
        <link rel='icon' href={`${basePath}/favicon.ico`} />
        <meta name='viewport' content='width=device-width, initial-scale=1' />
        <meta name='description' content='Interactive QuadTree spatial partitioning visualizer with physics simulation' />
      </Head>

      {/* Loading Screen */}
      <div
        id="loading-screen"
        className={loading ? '' : 'hidden'}
        style={{
          backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.9), rgba(0, 0, 0, 0.8)), url('https://github.com/Amey-Thakur/QUADTREE-VISUALIZER/raw/main/25-04-2022/2022-04-25%20at%2010.53.19.jpeg')`,
          backgroundSize: 'cover',
          backgroundPosition: 'center',
          backgroundRepeat: 'no-repeat'
        }}
      >
        <div className="loader-content">
          <div style={{ color: '#fff', marginBottom: '30px', textShadow: '0 2px 4px rgba(0,0,0,0.5)' }}>
            <h3 style={{ margin: '0 0 8px 0', fontSize: '1.1rem', fontWeight: 500, fontFamily: "'Play', sans-serif" }}>
              Presented as part of the BE Major-Project @ Terna Engineering College
            </h3>
            <p style={{ margin: '0', fontSize: '0.85rem', opacity: 0.8, fontFamily: "'Play', sans-serif" }}>
              Project Authors: Amey Thakur, Hasan Rizvi, Mega Satish and Ajay Davare <br /> (Group: Phi-CS-73, Batch of: 2022)
            </p>
          </div>

          <div className="progress-container">
            <div className={`progress-bar ${loading ? 'simulating' : ''}`} id="main-progress-bar"></div>
          </div>
          <p className="loading-text">Loading QuadTree Visualizer...</p>
        </div>
      </div>

      <Component {...pageProps} />
    </ThemeProvider>
  )
}


export default MyApp
