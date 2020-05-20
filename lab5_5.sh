#!/bin/bash
export count=0
if [ -f "$1" ]; then
	echo "The name of the file is: $1"
	nrCharacters=`cat $1 | wc -m`
	echo "The number of characters is: $nrCharacters"
	nrLines=`cat $1 | wc -l`
	echo "The number of lines is : $nrLines"
elif [ -d "$1" ]; then
    
     find $1 -type f | ( while read F; do
     count=$(($count+1))
     done 
     echo "The number os files is: $count" )
else
      echo "The argument should be a file/directory ! "
fi
