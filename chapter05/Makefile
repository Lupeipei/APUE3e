ROOT=..

PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 5_4_getc_putc 5_5_fgets_fputs 5_11_buffered 5_12_tempfile 5_13_mkstemp 5_15_memo_stream

all: $(PROGS)

%: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.err
include $(ROOT)/Make.libapue.inc
