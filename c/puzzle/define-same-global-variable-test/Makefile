# $@ - target
# S^ - all dependencies
# $< - first dependency

a.out: main.o module.o
	gcc -o $@ $^

# if .h changed, target should be updated
main.o: main.c inc.h
	gcc -c $<

module.o: module.c inc.h
	gcc -c $<
