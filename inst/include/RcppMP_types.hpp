// RcppMP_types.hpp: multi-precision libs glue.
//
// Copyright (C) 2014 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_TYPES_HPP
#define RCPPMP_TYPES_HPP

#include <RcppCommon.h>

#include <gmpxx.h>
#include <mpfr.h>
#include <mpreal.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <boost/multiprecision/cpp_int.hpp>
#pragma GCC diagnostic pop

namespace Rcpp {

// gmp
template <> SEXP wrap(const mpq_class &);
template <> SEXP wrap(const mpz_class &);
// mpfr
template <> SEXP wrap(const mpfr_t &);
// mpreal
template <> SEXP wrap(const mpfr::mpreal &);
template <> SEXP wrap(const std::vector<mpfr::mpreal> &);
// boost multiprecision
template <> SEXP wrap(const boost::multiprecision::cpp_int &);

} // namespace Rcpp

#include <Rcpp.h>

#include <RcppMP_gmp.hpp>
#include <RcppMP_mpfr.hpp>
#include <RcppMP_mpreal.hpp>
#include <RcppMP_boost.hpp>

#endif /* RCPPMP_TYPES_HPP */
