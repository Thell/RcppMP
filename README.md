Just a few `wrap()` functions to pass from Rcpp to Rmpfr with some samples in `tests/testthat/cpp`

wraps:  
  - singular `mpfr_t`
  - singular `mpreal`
  - `std::vector<mpreal>`

The Rmpfr `S4` still needs attributes (ie. to be an array or matrix with dims)

