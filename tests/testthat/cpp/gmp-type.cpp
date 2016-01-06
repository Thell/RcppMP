// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppMP)]]

#include <RcppMP.h>

using namespace Rcpp;

// [[Rcpp::export("as.bigz_uint32")]]
SEXP as_bigz_uint32(uint32_t x) {
  mpz_class xmp(x);
  return wrap(xmp);
}

// [[Rcpp::export("as.bigz_str")]]
SEXP as_bigz_str(std::string x) {
  mpz_class xmp(x);
  return wrap(xmp);
}

// [[Rcpp::export("as.bigq_uint32")]]
SEXP as_bigq_uint32(uint32_t n, uint32_t d) {
  mpq_class xmp(n, d);
  return wrap(xmp);
}

// [[Rcpp::export("as.bigq_str")]]
SEXP as_bigq_str(std::string n, std::string d) {
  mpq_class xmp(n);
  xmp /= mpq_class(d);
  return wrap(xmp);
}
