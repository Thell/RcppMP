// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppMP)]]

#include <RcppMP.h>

using namespace Rcpp;

// [[Rcpp::export("as.bigz_uint32")]]
RawVector as_bigz_uint32(uint32_t x) {
  mpz_class xmp(x);
  return wrap(xmp);
}

// [[Rcpp::export("as.bigz_str")]]
RawVector as_bigz_str(std::string x) {
  mpz_class xmp(x);
  return wrap(xmp);
}
