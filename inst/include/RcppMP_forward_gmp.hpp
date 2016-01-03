// RcppMP_forward_gmp.hpp: multi-precision gmp lib glue.
//
// Copyright (C) 2014 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_FORWARD_GMP_HPP
#define RCPPMP_FORWARD_GMP_HPP

namespace Rcpp {

template <> SEXP wrap(const mpz_class &);

} // namespace Rcpp

#endif /* RCPPMP_FORWARD_GMP_HPP */
