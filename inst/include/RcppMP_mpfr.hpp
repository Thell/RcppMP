// RcppMP_forward_mpfr.hpp: multi-precision libs glue.
//
// Copyright (C) 2014 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_MPFR_HPP
#define RCPPMP_MPFR_HPP

#ifndef RCPPMP_COMPILING

#include "RcppMP_forward_mpfr.hpp"

namespace Rcpp {

template <> SEXP wrap(const mpfr_t &x) {

  constexpr auto rlimb_factor(GMP_NUMB_BITS / 32); // 1 or 2
  constexpr auto mask(0x00000000FFFFFFFFL);

  uint32_t limbs(1 + ((x->_mpfr_prec - 1) / mp_bits_per_limb));
  IntegerVector out_data(rlimb_factor * limbs);
  IntegerVector out_exp(2);

  #if GMP_NUMB_BITS == 32
    out_exp[0] = x->_mpfr_exp;
    for (int i = 0; i < limbs; i++) {
      out_data[i] = (uint32_t)x->_mpfr_d[i];
    }
  #elif GMP_NUMB_BITS == 64
    out_exp[0] = x->_mpfr_exp & mask;
    out_exp[1] = x->_mpfr_exp >> 32;
    for (int i = 0, j = 0; j < limbs; i += 2, j++) {
      out_data[i] = (uint32_t)(x->_mpfr_d[j] & mask);
      out_data[i + 1] = (uint32_t)(x->_mpfr_d[j] >> 32);
    }
  #endif

  S4 out("mpfr1");
  out.slot("prec") = (int32_t)x->_mpfr_prec;
  out.slot("exp") = out_exp;
  out.slot("sign") = (int32_t)x->_mpfr_sign;
  out.slot("d") = out_data;

  return out;
}

} // namespace rcpp


#endif /* RCPPMP_COMPILING */

#endif /* RCPPMP_MPFR_HPP */
