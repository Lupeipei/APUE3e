ROOT=..

PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 8_1_fork 8_3_vfork 8_6_wait 8_8_waitpid 8_12_race 8_16_exec echoall 8_20_testinterp
MOREPROGS = 8_23_system 8_24_tsys 8_25_printuids 8_28_generate_acc 8_29_pracct 8_30_nice 8_31_pr_times

all: $(PROGS) $(MOREPROGS)

%: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(MOREPROGS) $(TEMPFILES) *.o echoall
include $(ROOT)/Make.libapue.inc
