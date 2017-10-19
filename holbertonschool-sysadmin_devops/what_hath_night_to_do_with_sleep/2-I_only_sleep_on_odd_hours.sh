#!/bin/bash
if [ $[$1 % 2] = 0 ]; then
    echo "Heh?"
else
    echo "Sleep time!"
fi
