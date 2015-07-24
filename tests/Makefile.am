#==============================================================================#
# Process this file with automake to produce Makefile.in
#
# Contributor: Chen Ye <ycchina@gmail.com>
#==============================================================================#

TESTS = test_path
check_PROGRAMS = test_path
test_path_SOURCES = test_path.c $(top_builddir)/src/path.h
test_path_CFLAGS = @CHECK_CFLAGS@
test_path_LDADD = $(top_builddir)/src/libpath.la @CHECK_LIBS@
