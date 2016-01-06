// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppMP, BH)]]

#include <RcppMP.h>

using namespace Rcpp;
using mpfr::mpreal;

// [[Rcpp::export("as.mpfr1")]]
S4 as_mpfr1(double x, unsigned long prec) {
  auto xmp(mpreal(x, prec));
  return wrap(xmp);
}

// [[Rcpp::export("as.mpfr")]]
S4 as_mpfr(double x, unsigned long prec) {
  auto xmp(mpreal(x, prec));
  S4 out("mpfr");
  out.slot(".Data") = List::create(wrap(xmp));
  return out;
}

// [[Rcpp::export("as.mpfrvec")]]
S4 as_mpfrvec(Rcpp::NumericVector x, unsigned long prec) {
  mpreal::set_default_prec(prec);
  std::vector<mpreal> xmp(x.begin(), x.end());
  return (wrap(xmp));
}

// [[Rcpp::export("as.mpfrvec2")]]
S4 as_mpfrvec2(Rcpp::NumericVector x, std::vector<unsigned long int> prec) {
  std::vector<mpreal> xmp;
  xmp.reserve(x.size());
  size_t p(0), p_lim(prec.size());
  for (auto &e : x) {
    if (p == p_lim) p = 0;
    xmp.push_back(mpreal(e, prec[p++]));
  }
  return (wrap(xmp));
}

// [[Rcpp::export("as.mpfrarray")]]
S4 as_mpfrarr(Rcpp::NumericVector x, unsigned long prec) {
  mpreal::set_default_prec(prec);
  std::vector<mpreal> xmp(x.begin(), x.end());
  S4 out("mpfrArray");
  out.slot(".Data") = wrap(xmp);
  out.slot("Dim") = Dimension(x.size());
  out.slot("Dimnames") = List::create(R_NilValue);
  return out;
}
