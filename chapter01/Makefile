ROOT=..

PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 1_3_ls1 1_4_mycat 1_5_getcputc 1_6_hello 1_7_shell1 1_8_testerror 1_9_uidgid 1_10_shell2

all: $(PROGS)

%: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o
include $(ROOT)/Make.libapue.inc
