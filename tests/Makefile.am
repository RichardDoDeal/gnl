## Process this file with automake to produce Makefile.in

TESTS = check_get_next_line

check_PROGRAMS = check_get_next_line

HEADER = $(top_builddir)/src/get_next_line.h
LIB = $(top_builddir)/src/libget_next_line.la

check_get_next_line_SOURCES = check_get_next_line.c $(HEADER)
check_get_next_line_CFLAGS = @CHECK_CFLAGS@
check_get_next_line_LDADD = $(LIB) @CHECK_LIBS@

#check_get_next_line_utils_SOURCES = check_get_next_line_utils.c $(HEADER)
#check_get_next_line_utils_CFLAGS = @CHECK_CFLAGS@
#check_get_next_line_utils_LDADD = $(LIB) @CHECK_LIBS@