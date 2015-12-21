// [[Rcpp::interfaces(r, cpp)]]

#include <testthat.h>
#include <Rcpp.h>

//' @export
// [[Rcpp::export]]
int twoPlusTwo() { return 2 + 2; }

context("exported") {
  test_that("two plus two equals four") { expect_true(twoPlusTwo() == 4); }
}

CATCH_TEST_CASE("twoPlusTwo", "[exported]") { CATCH_CHECK(twoPlusTwo() == 4); }
