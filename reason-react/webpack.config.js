const path = require('path');

module.exports = {
  entry: {
    challenges: './lib/js/src/challenges/root.js'
  },
  output: {
    path: path.join(__dirname, "public"),
    filename: '[name].js',
  },
};
