var webpack = require("webpack");
var path = require("path");

var APP_DIR = path.resolve(__dirname, "js");
var BUILD_DIR = path.resolve(__dirname, "static");
var NODE_MODULES = path.resolve(__dirname, "node_modules");
var CSS_DIR = path.resolve(__dirname, "styles");

var APP_ROOT = "/app.js";
var BUNDLE_NAME = "bundle.js"

module.exports = {
    entry: [
        'webpack-dev-server/client?http://0.0.0.0:8080',
        'webpack/hot/only-dev-server',
        APP_DIR + APP_ROOT,
    ],
    output: {
        path: BUILD_DIR,
        publicPath: "/static/",
        filename: BUNDLE_NAME,
    },
    resolve: {
        root: [
            path.resolve("./"),
            path.resolve("./node_modules"),
        ]
    },
    plugins: [
        new webpack.HotModuleReplacementPlugin()
    ],
    module: {
        loaders: [{
            loader: "babel",
            test: /\.jsx?$/,
            include: APP_DIR,
        },
        {
            test: /\.css$/,
            loader: 'style-loader',
        }, 
        {
            test: /\.css$/,
            loader: 'css-loader',
            query: {
                modules: true,
                localIdentName: '[name]__[local]___[hash:base64:5]'
            }
        }]
    }
};

