// forward.hpp: multi-precision mpfrc++ (mpreal) lib glue.
//
// Copyright (C) 2014 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_FORWARD_MPREAL_HPP
#define RCPPMP_FORWARD_MPREAL_HPP

#include <mpreal.h>

namespace Rcpp {

template <> SEXP wrap(const mpfr::mpreal &);
template <> SEXP wrap(const std::vector<mpfr::mpreal> &);

} // namespace Rcpp

#endif /* RCPPMP_FORWARD_MPREAL_HPP */
