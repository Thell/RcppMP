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

template <> SEXP wrap(const mpfr::mpreal &in) {
  constexpr auto rlimb_factor(GMP_NUMB_BITS / 32); // 1 or 2
  constexpr auto mask(0x00000000FFFFFFFFL);

  mpfr_srcptr src(in.mpfr_srcptr());
  uint32_t limbs(1 + ((src->_mpfr_prec - 1) / mp_bits_per_limb));
  IntegerVector out_data(rlimb_factor * limbs);
  IntegerVector out_exp(2);

#if GMP_NUMB_BITS == 32
  out_exp[0] = src->_mpfr_exp;
  for (int i = 0; i < limbs; i++) {
    out_data[i] = (uint32_t)src->_mpfr_d[i];
  }
#elif GMP_NUMB_BITS == 64
  out_exp[0] = src->_mpfr_exp & mask;
  out_exp[1] = src->_mpfr_exp >> 32;
  for (int i = 0, j = 0; j < limbs; i += 2, j++) {
    out_data[i] = (uint32_t)(src->_mpfr_d[j] & mask);
    out_data[i + 1] = (uint32_t)(src->_mpfr_d[j] >> 32);
  }
#endif

  S4 out("mpfr1");
  out.slot("prec") = (int32_t)src->_mpfr_prec;
  out.slot("exp") = out_exp;
  out.slot("sign") = (int32_t)src->_mpfr_sign;
  out.slot("d") = out_data;

  return (out);
}

template <> SEXP wrap(const std::vector<mpfr::mpreal> &x) {
  List xS4(x.size());
  for (size_t i = 0; i < x.size(); ++i) {
    xS4[i] = Rcpp::wrap(x[i]);
  }

  S4 out("mpfr");
  out.slot(".Data") = xS4;
  return out;
}

} // namespace Rcpp

#endif // RCPPMP_COMPILING

#endif /* RCPPMP_MPREAL_HPP */
