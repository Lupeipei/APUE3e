ROOT=..

PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 11_2_printids 11_3_pthread_join 11_4_pthread_exit 11_5_pthread_cleanup

all: $(PROGS)

%: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o
include $(ROOT)/Make.libapue.inc
