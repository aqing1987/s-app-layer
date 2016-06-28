#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: sh $0 flash-plugin"
    exit 1
fi

flashtar="$1"
basetar=`basename $1`
dstdir="/tmp/flash-install"

if [ -f $flashtar ]; then
    mkdir -p $dstdir
    mv $flashtar $dstdir
    cd $dstdir; tar xf $basetar; sudo cp *.so /usr/lib/mozilla/plugins/; sudo cp -a usr/* /usr
    echo "install finished, restart your firefox now!"
else
    echo "$flashtar not exist !!!"
fi
