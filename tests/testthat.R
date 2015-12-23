require("testthat", quietly = TRUE)

Sys.setenv("R_TESTS" = "")
test_check("RcppMP", reporter = "Tap")
