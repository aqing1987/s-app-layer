#!/bin/sh

#
# eval [arguments]
# The arguments are concatenated together into a single command, which is then
# read and executed, and its exit status returned as the exit status of eval. If
# there are no arguments or only empty arguments, the return status is zero.
#

read_val="cat ./eval-test.sh"

echo "--- 1 (not execute cat)"
echo $read_val

echo "--- 2 (execute cat)"
eval $read_val
