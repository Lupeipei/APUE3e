ROOT=..

PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 14_1_nonblock 14_7_deadlock 14_12_mandatory_lock 14_20_translate1 14_21_translate2 14_27_mmap

all: $(PROGS)

%: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o templock
include $(ROOT)/Make.libapue.inc
