#!/bin/bash

export sum=0
export nrFiles=0
find -type f | (while read f; do
   isText=$(file "$f" | grep -c "text")
   if [ $isText -eq 1 ]; then
	   
	   nrFiles=$(($nrFiles + 1))
	   nrLines=`cat "$f" |wc -l`
	   sum=$(( $sum + $nrLines ))
	  
   fi
done

     average=$(($sum/$nrFiles))
     echo "The current directory has $nrFiles files with a total of $sum lines and the minimum number of lines is $average")

