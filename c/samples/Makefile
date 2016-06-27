
cc=~/workspace/hos-r21/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-gcc
#cc=gcc

src=check-file-opened.c
#cflags = -pthread -g -Wall
cflags=-g -Wall

all : $(src)
	$(cc) $(src) $(cflags)

.PHONY : clean
clean:
	rm $(exe) *.o
