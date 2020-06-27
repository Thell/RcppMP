library(RcppMP)

## Test boost type wrapping.
Rcpp::sourceCpp("cpp/boost-type.cpp")

## Wrapping of boost types results in R class type.
expect_equal(class(as.bigz_cpp_int(123)), "bigz") #, Type wraps cpp_int=>bigz
expect_equal(class(as.bigq_cpp_rational(123, 456)), "bigq") #, Type wraps cpp_rational=>bigq

## Wrapping of cpp_int matches 'as.bigz()' value.
expect_identical(as.bigz_cpp_int(123), gmp::as.bigz(123)) #, as. wrap int bigz
expect_identical(as.bigz_cpp_int_str("123"), gmp::as.bigz("123")) #, as. wrap int string bigz

## Wrapping of cpp_rational matches 'as.bigq()' value.
expect_identical(as.bigq_cpp_rational(123, 456), gmp::as.bigq(123, 456)) #, as. wrap ints bigq
expect_identical(as.bigq_cpp_rational_str("123", "456"), gmp::as.bigq("123", "456")) #, as. wrap int strings bigq
