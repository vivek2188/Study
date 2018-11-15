#!/bin/sh

read file_name

count=0
flag=0

while read line
do 
	flag=0
	for word in $line
	do
		if [ "$word" = "Dog" ]
		then
			count=`expr ${count} + 1`
			flag=1	
		fi
		if [ $flag -eq 1 ]
		then 
			break
		fi
	done
done < $file_name

echo "The total number of lines that contain dog: $count"
