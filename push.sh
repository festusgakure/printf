#!/bin/bash
echo " enter commit message "
read  message
git add .
git commit -m "$message"
git push
