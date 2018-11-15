#!/bin/sh

read num

fact=1	# Initialising the factorial value
i=1

while [ $i -le $num ]
do
	fact=`expr $fact \* $i`
	i=`expr $i + 1`
done

echo $fact
