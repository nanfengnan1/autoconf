UTOMAKE_OPTIONS=foreign subdir-objects 1.12

SUBDIRS=src lib

bin_PROGRAMS=a
a_LDADD=src/librx.la lib/librb.la

.PHONY: auto_clean

auto_clean: distclean
	find . -name Makefile.in -exec rm -f {} \;
	rm -rf autom4te.cache
	rm -f missing aclocal.m4 config.h.in config.h.in~ config.guess config.sub ltmain.sh install-sh configure depcomp compile
