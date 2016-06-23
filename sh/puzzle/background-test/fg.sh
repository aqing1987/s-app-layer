#!/bin/sh

echo "fore ground task running"

# though fg.sh killed, the background bg.sh still running
sh bg.sh &

sleep 10