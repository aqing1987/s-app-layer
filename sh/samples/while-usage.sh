#!/bin/sh

# test while loop

if [ $# -ne 1 ]; then
	echo "usage: $0 integer"
	exit 1
fi

n=$1
i=0
while [ $i -le 10 ]
do
	echo "$n * $i = `expr $i \* $n`"
	i=`expr $i + 1`
done
