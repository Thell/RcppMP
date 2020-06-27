library(RcppMP)

# Rmpfr has mpfr1, mpfr, mpfrArray and mpfrMatrix classes.

## Test mpreal type wrapping.
Rcpp::sourceCpp("cpp/mpreal-type.cpp")

## Wrapping of mpreal results in Rmpfr class types.
expect_true(is(as.mpfr1(1,113), "mpfr1")) #, as.mpfr1
expect_true(is(as.mpfr(1,113), "mpfr")) #, as.mpfr
expect_true(is(as.mpfrvec(1:3, 113), "mpfr")) #, as.mpfrvec
expect_true(is(as.mpfrvec2(1:3, c(23,64,113)), "mpfr")) #, as.mpfrvec2
expect_true(is(as.mpfrarray(1:3, 113), "mpfrArray")) #, as.mpfrarray

## Wrapping of mpreal matches Rmpfr values.
expect_identical(as.mpfr1(1,113), Rmpfr::mpfr(1,113)@.Data[[1]]) #, as.mpfr1
expect_identical(mapply( as.mpfr, 1:1000, 2^(1:10), SIMPLIFY = FALSE ),
                 mapply( Rmpfr::mpfr, 1:1000, 2^(1:10), SIMPLIFY = FALSE )) #, as.mpfr
expect_identical(as.mpfrvec(1:1000, 113), Rmpfr::mpfr(1:1000, 113)) #, as.mpfrvec
expect_identical(as.mpfrvec2(1:1000, c(23,62,113)), Rmpfr::mpfr(1:1000, c(23,62,113))) #, as.mpfrvec2
expect_identical(as.mpfrarray(1:1000, 113), Rmpfr::mpfrArray(1:1000, 113)) #, as.mpfrarray
