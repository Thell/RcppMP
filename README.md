Just a few `wrap()` functions to pass from Rcpp to Rmpfr with some samples in `inst/tinytest`.

Using `string` for `Rgmp` types and populating the `S4` object for `Rmpfr`.

wraps:  
  - singular `cpp_int` to `bigz`
  - singular `cpp_rational` to `bigq`
  - singular `mpfr_t` to `mpfr`
  - singular `mpq_class` to `bigq`
  - singular `mpreal` to `mpfr`
  - singular `mpz_class` to `bigz`
  - `std::vector<mpreal>` to `mpfr` vector w/o dims

The Rmpfr `S4` still needs attributes (ie. to be an array or matrix with dims)

```r
> library(RcppMP)
> tinytest::test_package("RcppMP")
```
```
Running test-accessibility.R..........    4 tests OK 
Running test-boost-type.R.............    6 tests OK 
Running test-gmp-type.R...............    6 tests OK 
Running test-mpfr-type.R..............    2 tests OK 
Running test-mpreal-type.R............   10 tests OK 
[1] "All ok, 28 results"
```
