#!/bin/bash
echo $2 &> /tmp/4-stdout_and_stderr
$1 >> /tmp/4-stdout_and_stderr 2>&1
cat /tmp/4-stdout_and_stderr
