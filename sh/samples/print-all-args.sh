#!/bin/sh

echo "total param num = $#"
args_num=$#
i=0
while [ $i -lt $args_num ]
do
	echo "${i}th"

    echo $1
    shift 1

    i=`expr $i + 1`
done
