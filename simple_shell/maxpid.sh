#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)

echo "The maximum value a process ID can be is: $pid_max"
