#!/bin/bash

if [ $# -eq 0 ]
then
	dir="."
else
	dir=$1
fi

if [ -d "$dir" ]
then 
	for file in "$dir"/*
	do
		filename=$(basename $file)
		if [ -d "$file" ]
		then
			echo -n "디렉터리 $filename을(를) 삭제하시겠습니까? (yes/no) : "
			read answer
			if [ $answer == "yes" ]
			then
				rm -r $file
			fi
		else
			echo -n "$filename을(를) 삭제하시겠습니까? (yes/no) : "
			read answer
			if [ $answer == "yes" ]
			then
				rm -r $file
			fi
		fi
		
	done
else
	echo "$0: $1 디렉터리 아님"
fi
