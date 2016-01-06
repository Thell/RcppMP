Just a few `wrap()` functions to pass from Rcpp to Rmpfr with some samples in `tests/testthat/cpp`.

Using `string` for `Rgmp` types and populating the `S4` object for `Rmpfr`.

wraps:  
  - singular `mpfr_t` to `mpfr`
  - singular `mpq_class` to `bigq`
  - singular `mpreal` to `mpfr`
  - singular `mpz_class` to `bigz`
  - `std::vector<mpreal>` to `mpfr` vector w/o dims

The Rmpfr `S4` still needs attributes (ie. to be an array or matrix with dims)

