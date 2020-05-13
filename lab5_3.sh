#!/bin/bash

find -type f | ( while read F; do
    isText=$(file "$F" | grep -c "text")
    if [ $isText -eq 1 ]; then
	    echo "$F has the following lines: "
	    count=`cat $F | wc -l`
	    if [ $count -lt 10 ]; then
		    echo "`cat $F`"
	    else
		   echo "`head -5 "$F"`"
                   echo "`tail -n 5 "$F"`"
            fi
fi
done)
