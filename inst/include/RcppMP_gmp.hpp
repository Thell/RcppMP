// RcppMP_gmp.hpp: multi-precision gmp lib glue.
//
// Copyright (C) 2014 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_GMP_HPP
#define RCPPMP_GMP_HPP

namespace Rcpp {

template<> SEXP wrap(const mpz_class &x) {
  Function bigz("as.bigz", "gmp");
  return bigz(wrap(x.get_str()));
}

template<> SEXP wrap(const mpq_class &x) {
  Function bigq("as.bigq", "gmp");
  return bigq(wrap(x.get_str()));
}

} // namespace Rcpp

#endif /* RCPPMP_GMP_HPP */
