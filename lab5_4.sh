#!/bin/bash

dir = $1
for file in $(find $directory -depth -type f -perm /a+w)
do
	mv $file $file.all
done
