#!/bin/bash
while [ $# -ne 0 ]; do
	file=$1
	word=$2
	number=$3
	grep "^\(.*\<$word\>.*\)\{$number\}$" $file
	shift 3
done
