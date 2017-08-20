const path = require('path');
const webpack = require('webpack');

module.exports = {
  entry: {
    challenges: './lib/js/src/challenges/root.js'
  },
  output: {
    path: path.join(__dirname, "public"),
    filename: '[name].min.js',
  },
  plugins: [
    new webpack.DefinePlugin({
      'process.env': {
        NODE_ENV: JSON.stringify('production')
      }
    }),
    new webpack.optimize.UglifyJsPlugin()
  ]
};
