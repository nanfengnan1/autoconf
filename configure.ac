#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(test_autoconf, 0.0.1, 1579628578@qq.com)

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_SRCDIR([a.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# print msg function
#AC_MSG_ERROR(["******************stop: ${LIBYANG_CFLAGS}******************"])

# add optional feature
AC_ARG_ENABLE([pcreposix],
  AS_HELP_STRING([--enable-pcreposix], [enable using PCRE Posix libs for regex functions]))
AC_ARG_ENABLE([protobuf],
  AS_HELP_STRING([--enable-protobuf], [Enable experimental protobuf support]))
AC_ARG_ENABLE([address-sanitizer],
  AS_HELP_STRING([--enable-address-sanitizer], [enable AddressSanitizer support for detecting a wide variety of memory allocation and deallocation errr
ors]))
AC_ARG_ENABLE([thread-sanitizer],
  AS_HELP_STRING([--enable-thread-sanitizer], [enable ThreadSanitizer support for detecting data races]))
AC_ARG_ENABLE([memory-sanitizer],
  AS_HELP_STRING([--enable-memory-sanitizer], [enable MemorySanitizer support for detecting uninitialized memory reads]))
AC_ARG_ENABLE(tcmalloc,
        AS_HELP_STRING([--enable-tcmalloc], [Turn on tcmalloc]),
[case "${enableval}" in
  yes) tcmalloc_enabled=true
LIBS="$LIBS -ltcmalloc_minimal"
 ;;
  no)  tcmalloc_enabled=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-tcmalloc]) ;;
esac],[tcmalloc_enabled=false])

# check prog, library, header, struct
if test "$enable_protobuf" = "yes"; then

	# check for prog
	AC_CHECK_PROGS([TEST], [test], [/bin/false])

	if test "$TEST" = "/bin/false"; then
	    AC_MSG_FAILURE([test requested but test not found.  Install test.])
	fi

	# check for library
	PKG_CHECK_MODULES([PCRE], [libpcre >= 1],, [
		AC_MSG_FAILURE([pcre2 requested but test not found.])
	])

	# check for header
	AC_CHECK_HEADER([pthread.h], [], [
		AC_MSG_FAILURE([pthread rquested but pthread.h not found.])
	])

	# check function
	AC_CHECK_FUNC([printf], [
	  AC_DEFINE(HAVE_PRINTF, 1, [Define to 1 if you have the `printf' function.])
	  AC_MSG_NOTICE([Found printf function])
	], [
	  AC_MSG_ERROR([printf function not found])
	])

	# check for type
	dnl this will disappear
	AC_CHECK_TYPES([
		struct __db_lsn,
		struct __db_log_cursor, struct __db_log_stat, struct __db_lockreq,
		struct __db_lock_u, struct __db_lock_pstat],
		[],
		[], db.h)dnl

	# check for struct member
	AC_CHECK_MEMBER([struct _pthread_cleanup_buffer.__arg], [], [
	  AC_MSG_ERROR([m4_normalize([
	    libyang needs to be compiled with ENABLE_LYD_PRIV=ON.
	    See http://docs.frrouting.org/projects/dev-guide/en/latest/building-libyang.html for details.])
	  ])
	], [[#include <pthread.h>]])

	AC_DEFINE([HAVE_PROTOBUF], [1], [protobuf])
fi

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
	Makefile
   	lib/Makefile
   	src/Makefile
])

AC_OUTPUT
