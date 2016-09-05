#!/bin/sh

demo()
{
	echo "all function args: $*"
	echo "the first arg : $1"
	echo "the second arg : $2"
	echo "the third arg : $3"
}

# call the function
demo -f foo bar

exit 0
