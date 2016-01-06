// RcppMP_boost.hpp: multi-precision boost lib glue.
//
// Copyright (C) 2014 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_BOOST_HPP
#define RCPPMP_BOOST_HPP

namespace Rcpp {

template <> SEXP wrap(const boost::multiprecision::cpp_int &x) {
  Function bigz("as.bigz", "gmp");
  return bigz(wrap(x.str()));
}

template<> SEXP wrap(const boost::multiprecision::cpp_rational &x) {
  Function bigq("as.bigq", "gmp");
  return bigq(wrap(x.str()));
}

} // namespace Rcpp

#endif /* RCPPMP_BOOST_HPP */
