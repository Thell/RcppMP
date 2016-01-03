// RcppMP_forward_mpfr.hpp: multi-precision libs glue.
//
// Copyright (C) 2014 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_FORWARD_MPFR_HPP
#define RCPPMP_FORWARD_MPFR_HPP

#include "RcppMP_types.hpp"

namespace Rcpp {

template <> SEXP wrap(const mpfr_t &);

} // namespace Rcpp

#endif /* RCPPMP_FORWARD_MPFR_HPP */
