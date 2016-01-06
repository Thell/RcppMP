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

#include <RcppMP_forward_gmp.hpp>
#include <RcppMP_forward_mpfr.hpp>
#include <RcppMP_forward_mpreal.hpp>
#include <RcppMP_forward_boost.hpp>

#include <Rcpp.h>

// #ifdef COMPILING_RCPPMP_PACKAGE
#include <RcppMP_gmp.hpp>
#include <RcppMP_mpfr.hpp>
#include <RcppMP_mpreal.hpp>
#include <RcppMP_boost.hpp>
// #endif

#endif /* RCPPMP_TYPES_HPP */
