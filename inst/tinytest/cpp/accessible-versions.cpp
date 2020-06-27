// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppMP, BH)]]

#include <Rcpp.h>
#include <RcppMP.h>

// [[Rcpp::export]]
Rcpp::List test_versions() { return RcppMP::rcppmpVersions(); }
