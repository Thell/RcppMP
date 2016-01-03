library(testthat)
context("mpfr-type")

Ipath <- paste0("-I", system.file("include", package = "RcppMP"))
Sys.setenv("PKG_CXXFLAGS" = Ipath)
Rcpp::sourceCpp("cpp/mpfr-type.cpp")

test_that("Wrapping of mpfr_t results in Rmpfr class type.", {
  expect_is(as.mpfr1(1,113), "mpfr1")
})

test_that("Wrapping of mpfr_t matches 'mpfr()' value.", {
  expect_identical(as.mpfr1(1,113), Rmpfr::mpfr(1,113)@.Data[[1]])
})

