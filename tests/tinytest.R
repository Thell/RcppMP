if (requireNamespace("tinytest", quietly=TRUE) &&
    utils::packageVersion("tinytest") >= "1.0.0") {
  Sys.setenv("R_TESTS"="")
  tinytest::test_package("RcppMP", ncpu=getOption("Ncpus", 1))
}
