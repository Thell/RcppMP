context("Accessibility")

test_that("Builds using sourceCpp and Rcpp::depends(RcppMP).", {
  expect_builds <- function(file) {
    Ipath <- paste0("-I", system.file("include", package = "RcppMP"))
    Sys.setenv("PKG_CXXFLAGS" = Ipath)
    Rcpp::sourceCpp(file)
    expect_true(built())
  }
  expect_builds("cpp/accessible-depends.cpp")
})

test_that("Accessible dependencies match R package versions.", {
  Ipath <- paste0("-I", system.file("include", package = "RcppMP"))
  Sys.setenv("PKG_CXXFLAGS" = Ipath)
  Rcpp::sourceCpp("cpp/accessible-versions.cpp")
  expect_equal(gmp:::.gmpVersion(), test_versions()[["GMP"]])
  expect_equal(Rmpfr:::.mpfrVersion(), test_versions()[["MPFR"]])
  expect_true(packageVersion("BH") >= test_versions()[["Boost"]])
})
