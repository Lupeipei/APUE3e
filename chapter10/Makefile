ROOT=..

PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 10_2_sigusr 10_5_my_alarm 10_6_sigcld 10_9_sleep2 10_10_read1 10_11_read2 10_15_sigprocmask
MOREPROGS = 10_20_sigjmp 10_22_sigsuspend1 10_23_sigsuspend2 10_26_system 10_31_sigtstp

all: $(PROGS) $(MOREPROGS)

%: %.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(MOREPROGS) $(TEMPFILES) *.o
include $(ROOT)/Make.libapue.inc
