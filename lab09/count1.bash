#!/bin/bash

if [ $# -eq 0 ]
then
	dir="."
else
	dir=$1
fi

echo -n $dir 내의 파일과 서브디렉터리 개수:
ls $dir | wc -l
