# Residual Benchmarking

This repository compiles some benchmarks for calculating residuals from a linear model in R.
The main variables that are tested are:
* The function and package used for calculating the residuals
* The storage of the matrix: either dense or sparse
* The shape of Y: either a vector or a matrix

In addition, a fast function for calculating residuals using the QR decomposition using Eigen is included.
