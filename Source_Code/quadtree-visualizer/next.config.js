/* eslint-disable no-undef */
const debug = process.env.NODE_ENV !== 'production'
module.exports = {
  exportPathMap: function () {
    return {
      '/': { page: '/' },
    }
  },
  assetPrefix: !debug ? '' : '',
}