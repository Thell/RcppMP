// mpreal.hpp: Rcpp templates for mpreal types.
//
// Copyright (C) 2012 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_MPREAL_HPP
#define RCPPMP_MPREAL_HPP

#ifndef RCPPMP_COMPILING

#include "RcppMP_forward_mpreal.hpp"

#include <cstdint>

namespace Rcpp {

template <> SEXP wrap(const mpfr::mpreal &x) {
  return wrap((mpfr_t){*x.mpfr_ptr()});
}

template <> SEXP wrap(const std::vector<mpfr::mpreal> &x) {
  List xS4(x.size());
  for (size_t i = 0; i < x.size(); ++i) {
    xS4[i] = wrap(x[i]);
  }

  S4 out("mpfr");
  out.slot(".Data") = xS4;
  return out;
}

} // namespace Rcpp

#endif // RCPPMP_COMPILING

#endif /* RCPPMP_MPREAL_HPP */
