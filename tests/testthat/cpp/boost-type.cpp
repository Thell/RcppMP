// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppMP, BH)]]

#include <RcppMP.h>

using namespace Rcpp;
using namespace boost::multiprecision;

// [[Rcpp::export("as.bigz_cpp_int")]]
RawVector as_bigz_uint32(uint32_t x) {
  cpp_int xmp(x);
  return wrap(xmp);
}

// [[Rcpp::export("as.bigz_cpp_int_str")]]
RawVector as_bigz_str(std::string x) {
  cpp_int xmp(x);
  return wrap(xmp);
}

// [[Rcpp::export("as.bigq_cpp_rational")]]
SEXP as_bigq_uint32(uint32_t n, uint32_t d) {
  cpp_rational xmp(n, d);
  return wrap(xmp);
}

// [[Rcpp::export("as.bigq_cpp_rational_str")]]
SEXP as_bigq_str(std::string n, std::string d) {
  cpp_rational xmp(n);
  xmp /= cpp_int(d);
  return wrap(xmp);
}
