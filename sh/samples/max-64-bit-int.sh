#!/bin/sh

# call by using 'bash filename'

# > 0 (max)
echo $((2**63-1))

# < 0 (min)
echo $((2**63))
