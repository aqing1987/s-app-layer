#!/bin/sh

var=$1

# POSIX
case $var in
    '' | *[!0-9]*)
        echo "$0: $var: invalid digit" >&2; exit 1;;
esac

echo "valid digit"
