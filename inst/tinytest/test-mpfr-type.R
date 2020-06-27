library(RcppMP)

## Test mpfr type wrapping.
Rcpp::sourceCpp("cpp/mpfr-type.cpp")

## Wrapping of mpfr_t results in Rmpfr class type.
expect_true(is(as.mpfr1(1,113), "mpfr1")) #, as.mpfr1

## Wrapping of mpfr_t matches Rmpfr value.
expect_identical(as.mpfr1(1,113), Rmpfr::mpfr(1,113)@.Data[[1]]) #, as.mpfr1
