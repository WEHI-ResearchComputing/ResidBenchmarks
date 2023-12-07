#include <RcppEigen.h>

using Eigen::Map;
using Eigen::EigenBase;
using Eigen::HouseholderQR;
using Eigen::MatrixXf;
using Eigen::SparseMatrix;
using Eigen::SparseQR;

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
SEXP qr_dense_residop(Map<MatrixXf> X, Map<MatrixXf> Y){
  const HouseholderQR<MatrixXf> QR(X);
  return Rcpp::wrap(Y - (X * QR.solve(Y)));
}

// [[Rcpp::export]]
SEXP qr_sparse_residop(Map<SparseMatrix<double>> X, Map<SparseMatrix<double>> Y){
  const SparseQR<SparseMatrix<double>> QR(X);
  return Rcpp::wrap(Y - (X * QR.solve(Y)));
}
