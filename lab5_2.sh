#!/bin/bash
find $1 -type f | ( while read F; do
   if [ `grep -c "[1-9][0-9]\{4,\}" $F` -ne 0 ]; then
	   echo $F
	fi
   
done )
