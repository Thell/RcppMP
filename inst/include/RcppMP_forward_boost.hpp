// RcppMP_forward_boost.hpp: multi-precision boost lib glue.
//
// Copyright (C) 2014 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

#ifndef RCPPMP_FORWARD_BOOST_HPP
#define RCPPMP_FORWARD_BOOST_HPP

namespace Rcpp {

template <> SEXP wrap(const boost::multiprecision::cpp_int &);

} // namespace Rcpp

#endif /* RCPPMP_FORWARD_BOOST_HPP */
