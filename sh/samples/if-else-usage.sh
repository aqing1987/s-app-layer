#!/bin/sh

if [ $# -ne 1 ]; then
	echo "$0 : you must give one integer"
	exit 1
fi

if [ $1 -gt 0 ]; then
	echo "$1 is positive"
else
	echo "$1 is negative"
fi
   
