# inline.R: plugin compile flags.
#
# Copyright (C) 2014 - 2016  Thell Fowler
#
# This file is part of the RcppMP package.
# It is distributed under the GNU GPL v3(+).

inlineCxxPlugin <- function(...) {
  plug <- Rcpp::Rcpp.plugin.maker(
    include.before = '#include <RcppMP.h>',
    libs           = "-lmpfr -lgmpxx -lgmp",
    package        = "RcppMP")
  plug()
}
