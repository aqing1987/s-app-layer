#!/bin/bash

if [ $(getconf WORD_BIT) = '32' ] && [ $(getconf LONG_BIT) = '64' ] ; then
    echo "64 bit OS"
else
    echo "32 bit OS"
fi
