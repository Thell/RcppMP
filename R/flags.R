# flags.R: Cxx compile flags.
#
# Copyright (C) 2014-2016  Thell Fowler
#
# This file is part of the RcppMP package.
# It is distributed under the GNU GPL v3(+).

RcppMPCxxFlags <- function(){
  o <- paste( '-I"', system.file( "include", package = "RcppMP" ), '"', sep = "" )
  if( "Windows" %in% Sys.info()[['sysname']] ) {
    o <- paste( o, paste(" -L '",
                         normalizePath( paste( Sys.getenv( "RTOOLS_LOCAL" ),
                                               "/lib/i386", collapse='',sep='' ),
                                        winslash='/' ), "'", sep="" ) )
  }
  o <- paste( o, " -lmpfr -lgmpxx -lgmp", sep="" )
  return( o )
}

CxxFlags <- function(){
  cat( RcppMPCxxFlags() )
}
