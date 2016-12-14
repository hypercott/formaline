Formaline Simple:

A truly simplistic example of how to preserve source code inside the executable that is compiled from it. The idea of Formaline goes back to Erik Schnetter, Research Technologies Group Lead, Perimeter Institute for Theoretical Physics.

See Makefile. The procedure is as follows:

(1) formaline_prepare.c -- code for an executable called 'formaline' that reads in a tar.gz ball of source code and creates a C source file that byte encodes the tar ball in a char array.

(2) A tar.gz ball of the source tree is created.

(3) The tar ball is fed into 'formaline', which outputs formaline.c, including the encoded tar ball.

(4) formaline.c is compiled and linked into the main executable formaline_test.

(5) upon execution, formaline_test (in source file source_file.c) calls the formaline_output function of formaline.c, which writes out the tar.gz ball into directory 'outdir/src' where 'outdir' is passed to formaline_output.


