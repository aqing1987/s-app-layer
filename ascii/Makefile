PROGS = get_ascii_code

OBJS = $(patsubst %, %.o, $(PROGS))

all: $(OBJS) $(PROGS)

$(OBJS): %.o : %.c
	$(CC) -c $(CFLAGS) $<

$(PROGS): %: %.o
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf $(PROGS) $(OBJS)
