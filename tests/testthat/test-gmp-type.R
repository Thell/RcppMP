library(testthat)
context("gmp-type")

# Rgmp has bigz and bigq classes which match up to the mpz_t and mpq_t
# of the gmp lib which are accessible in Rcpp most easily through the
# mpz_class and mpq_class of the gmp c++ interface.

Ipath <- paste0("-I", system.file("include", package = "RcppMP"))
Sys.setenv("PKG_CXXFLAGS" = Ipath)
Rcpp::sourceCpp("cpp/gmp-type.cpp")

test_that("Wrapping of gmp class results in Rgmp class type.", {
  expect_is(as.bigz_uint32(123), "bigz")
  expect_is(as.bigq_uint32(123, 456), "bigq")
})

test_that("Wrapping of mpz_class matches 'as.bigz()' value.", {
  expect_identical(as.bigz_uint32(123), gmp::as.bigz(123))
  expect_identical(as.bigz_str("123"), gmp::as.bigz("123"))
})

test_that("Wrapping of mpq_class matches 'as.bigq()' value.", {
  expect_identical(as.bigq_uint32(123, 456), gmp::as.bigq(123, 456))
  expect_identical(as.bigq_str("123", "456"), gmp::as.bigq("123", "456"))
})
