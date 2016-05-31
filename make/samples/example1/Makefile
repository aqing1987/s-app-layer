# $@ - target
# S^ - all dependencies
# $< - first dependency

exe: main.o s1.o s2.o
	gcc -o $@ $^

# if .h changed, target should be updated
main.o: main.c s1.h s2.h
	gcc -c $<

s1.o: s1.c s1.h
	gcc -c $<

s2.o: s2.c s2.h
	gcc -c $<
