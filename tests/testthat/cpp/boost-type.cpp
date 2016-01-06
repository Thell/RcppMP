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
