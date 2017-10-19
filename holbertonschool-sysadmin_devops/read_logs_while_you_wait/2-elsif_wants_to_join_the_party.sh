#!/bin/bash
HEAD_COUNT=0
GET_COUNT=0

grep "HEAD" "$1" | {
    while read -r line ; do
	HEAD_COUNT=$(($HEAD_COUNT+1))
    done
    echo $HEAD_COUNT
}
    
grep "GET" "$1" | {
    while read -r line ; do
	GET_COUNT=$(($GET_COUNT+1))
    done
    echo $GET_COUNT
}
