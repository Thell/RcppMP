library(RcppMP)

## Builds using sourceCpp and Rcpp::depends(RcppMP).
Rcpp::sourceCpp("cpp/accessible-depends.cpp")
expect_true(built()) #, "depends(RcppMP)"

## Accessible dependencies match R package versions.
Rcpp::sourceCpp("cpp/accessible-versions.cpp")
expect_equal(test_versions()[["GMP"]], gmp:::.gmpVersion()) #, accesses gmp
expect_equal(test_versions()[["MPFR"]], Rmpfr:::.mpfrVersion()) #, accesses mpfr
expect_true(test_versions()[["Boost"]] <= packageVersion("BH") ) #, accesses BH
