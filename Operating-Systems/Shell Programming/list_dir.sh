#!/bin/sh

count=0

for dir in *
do
	if [ -d $dir ]
	then
		echo $dir
		count=`expr $count + 1`
	fi
done

echo "Total number of directories are $count"
