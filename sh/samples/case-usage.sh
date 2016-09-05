#!/bin/sh

# test case statement

if [ $# -ne 1 ]; then
	echo "usage: $0 [a|b|c]"
	exit 1
fi

case $1 in
	"a" )
		echo "a select"
		;;
	"b" )
		echo "b select"
		;;
	"c" )
		echo "c select"
		;;
	* )
		echo "no action"
		;;
esac
