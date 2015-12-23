// RcppMP.cpp:
//
// Copyright (C) 2012 - 2016  Thell Fowler
//
// This file is part of the RcppMP package.
// It is distributed under the GNU GPL v3(+).

// [[Rcpp::interfaces(r, cpp)]]

#define COMPILING_RCPPMP_PACKAGE

#include <boost/version.hpp> // Boost lib version
#include <gmp.h>
#include <mpfr.h>
#include <mpreal.h> // mpfrc++

#include <Rcpp.h>

//' Library versions.
//'
//' @description Available multi-precision library versions.
//' @return List of named character vectors indicating the current
//'   versions.
//'
//' @export
// [[Rcpp::export]]
Rcpp::List rcppmpVersions() {
  using namespace Rcpp;

  auto boost_version = std::to_string(BOOST_VERSION / 100000) + "." +
                       std::to_string(BOOST_VERSION / 100 % 1000) + "." +
                       std::to_string(BOOST_VERSION % 100);

  List versions =
      List::create(Named("GMP") = wrap(gmp_version),
                   Named("MPFR") = wrap(mpfr_get_version()),
                   Named("Boost") = wrap(boost_version),
                   Named("MPFRC++") = wrap(std::string(MPREAL_VERSION_STRING)));

  return versions;
}

#undef COMPILING_RCPPMP_PACKAGE
