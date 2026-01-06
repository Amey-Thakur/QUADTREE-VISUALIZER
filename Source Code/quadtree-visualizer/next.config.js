/* eslint-disable no-undef */
const isProduction = process.env.NODE_ENV === 'production'
const basePath = isProduction ? '/QUADTREE-VISUALIZER' : ''

/** @type {import('next').NextConfig} */
module.exports = {
  basePath: basePath,
  assetPrefix: basePath,
  images: {
    unoptimized: true,
  },
  trailingSlash: true,
}