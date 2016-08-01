# $@ - target
# S^ - all dependencies
# $< - first dependency

a.out: test.o md5.o
	gcc -o $@ $^

# if .h changed, target should be updated
test.o: test.c
	gcc -c $<

md5.o: md5.c md5.h
	gcc -c $<

.PHONY : clean
clean :
	rm *.o a.out