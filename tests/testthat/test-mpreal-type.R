library(testthat)
context("mpreal-type")

# Rmpfr has mpfr1, mpfr, mpfrArray and mpfrMatrix classes.

Ipath <- paste0("-I", system.file("include", package = "RcppMP"))
Sys.setenv("PKG_CXXFLAGS" = Ipath)
Rcpp::sourceCpp("cpp/mpreal-type.cpp")

test_that("Wrapping of mpreal results in Rmpfr class types.", {
  expect_is(as.mpfr1(1,113), "mpfr1")
  expect_is(as.mpfr(1,113), "mpfr")
  expect_is(as.mpfrvec(1:3, 113), "mpfr")
  expect_is(as.mpfrvec2(1:3, c(23,64,113)), "mpfr")
  expect_is(as.mpfrarray(1:3, 113), "mpfrArray")
})

test_that("Wrapping of mpreal matches 'mpfr()' values.", {
  expect_identical(as.mpfr1(1,113), Rmpfr::mpfr(1,113)@.Data[[1]])
  expect_identical(mapply( as.mpfr, 1:1000, 2^(1:10), SIMPLIFY = FALSE ),
                   mapply( Rmpfr::mpfr, 1:1000, 2^(1:10), SIMPLIFY = FALSE ))
  expect_identical(as.mpfrvec(1:1000, 113), Rmpfr::mpfr(1:1000, 113))
  expect_identical(as.mpfrvec2(1:1000, c(23,62,113)), Rmpfr::mpfr(1:1000, c(23,62,113)))
  expect_identical(as.mpfrarray(1:1000, 113), Rmpfr::mpfrArray(1:1000, 113))
})

