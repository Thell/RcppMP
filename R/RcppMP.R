#' R multi-precision types for Rcpp.
#'
#' @description Basic Rcpp wrappers for gmp, mpfr and mpfr++ mpreal values.
#'
#' @references Extending Rcpp:
#'  \url{http://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-extending.pdf}
#' @references The GNU Multiple Precision Arithmetic Library
#'  \url{https://gmplib.org/}
#' @references The GNU MPFR Library
#'  \url{http://www.mpfr.org/}
#' @references MPFR C++ mpreal
#'  \url{http://www.holoborodko.com/pavel/mpfr/}
#' @references Boost.Multiprecision
#'  \url{http://www.boost.org/doc/libs/release/libs/multiprecision/doc/html/index.html}
#'
#' @seealso \link[Rcpp]{Rcpp} \link[gmp:bigz]{gmp bigz}
#'  \link[gmp:bigq]{gmp bigq} \link[Rmpfr]{Rmpfr} \link[BH]{BH}
#'
#' @keywords Rcpp multi-precision
#'
#' @docType package
#' @name RcppMP-package
#' @useDynLib RcppMP
#' @importFrom Rcpp sourceCpp evalCpp cppFunction Rcpp.plugin.maker
#' @importClassesFrom Rmpfr mpfr1 mpfr
#' @importClassesFrom gmp bigq bigz
NULL
