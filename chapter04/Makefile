ROOT=..

PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 4_3_filetype 4_8_access 4_9_umask 4_12_chmod 4_16_unlink 4_21_futimens 4_22_myftw 4_23_chdir 4_24_getcwd 4_25_dev_rdev

all: $(PROGS)

%: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o foo bar baz tempfile
include $(ROOT)/Make.libapue.inc
