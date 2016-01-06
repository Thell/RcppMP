library(testthat)
context("boost-type")

Ipath <- paste0("-I", system.file("include", package = "RcppMP"))
Sys.setenv("PKG_CXXFLAGS" = Ipath)
Rcpp::sourceCpp("cpp/boost-type.cpp")

test_that("Wrapping of boost types results in R class type.", {
  expect_is(as.bigz_cpp_int(123), "bigz")
  expect_is(as.bigq_cpp_rational(123, 456), "bigq")
})

test_that("Wrapping of cpp_int matches 'as.bigz()' value.", {
  expect_identical(as.bigz_cpp_int(123), gmp::as.bigz(123))
  expect_identical(as.bigz_cpp_int_str("123"), gmp::as.bigz("123"))
})

test_that("Wrapping of cpp_rational matches 'as.bigq()' value.", {
  expect_identical(as.bigq_cpp_rational(123, 456), gmp::as.bigq(123, 456))
  expect_identical(as.bigq_cpp_rational_str("123", "456"), gmp::as.bigq("123", "456"))
})
