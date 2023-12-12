#include <RcppEigen.h>

using Eigen::Map;
using Eigen::EigenBase;
using Eigen::HouseholderQR;
using Eigen::MatrixXd;
using Eigen::SparseMatrix;
using Eigen::SparseQR;
using Eigen::NaturalOrdering;

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
SEXP qr_dense_residop(Map<MatrixXd> X, Map<MatrixXd> Y){
  const HouseholderQR<MatrixXd> QR(X);
  return Rcpp::wrap(Y - (X * QR.solve(Y)));
}

// [[Rcpp::export]]
SEXP qr_sparse_residop(Map<SparseMatrix<double>> X, Map<MatrixXd> Y){
  const SparseQR<SparseMatrix<double>, NaturalOrdering<int>> QR(X);
  return Rcpp::wrap(Y - (X * QR.solve(Y)));
}
