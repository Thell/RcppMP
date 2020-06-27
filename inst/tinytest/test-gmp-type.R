library(RcppMP)

# Rgmp has bigz and bigq classes which match up to the mpz_t and mpq_t
# of the gmp lib which are accessible in Rcpp most easily through the
# mpz_class and mpq_class of the gmp c++ interface.

## Test gmp type wrapping.
Rcpp::sourceCpp("cpp/gmp-type.cpp")

## Wrapping of gmp class results in Rgmp class type.
expect_equal(class(as.bigz_uint32(123)), "bigz") #, as.bigz_uint32
expect_equal(class(as.bigq_uint32(123, 456)), "bigq") #, as.bigq_str

## Wrapping of mpz_class matches 'as.bigz()' value.
expect_identical(as.bigz_uint32(123), gmp::as.bigz(123)) #, as.bigz_uint32
expect_identical(as.bigz_str("123"), gmp::as.bigz("123")) #, as.bigq_str

## Wrapping of mpq_class matches 'as.bigq()' value.
expect_identical(as.bigq_uint32(123, 456), gmp::as.bigq(123, 456)) #, as.bigz_uint32
expect_identical(as.bigq_str("123", "456"), gmp::as.bigq("123", "456")) #, as.bigq_str
