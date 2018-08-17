PROGS = cli srv

all: $(PROGS)

srv: srv.c
cli: cli.c

.PHONY: clean

clean:
	rm -rf *.o socket $(PROGS)
