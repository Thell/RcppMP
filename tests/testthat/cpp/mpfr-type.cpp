// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppMP)]]

#include <RcppMP.h>

using namespace Rcpp;

/*
 * Can't just return wrap(xmp) since clear must be called...
 */
// [[Rcpp::export("as.mpfr1")]]
S4 as_mpfr1(double x, unsigned long prec) {
  mpfr_t xmp;
  mpfr_init2(xmp, prec);
  mpfr_set_d(xmp, x, MPFR_RNDN);
  auto xs4 = wrap(xmp);
  mpfr_clear(xmp);
  return xs4;
}
