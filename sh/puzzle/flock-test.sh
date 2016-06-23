#!/bin/sh

(
    flock -n 6
    # ... commands executed under lock ...
    if [ "$?" -eq 1 ]; then
        echo "cannot lock"
        exit 1
    fi

    sleep 10

    echo "done"

    exit 0
) 6<>"flock-test.sh"

