ROOT=..

PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 3_1_seek 3_2_hole 3_5_mycat 3_11_fileflags 3_12_setfl

all: $(PROGS)

%: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o file.hole file.nohole
include $(ROOT)/Make.libapue.inc
