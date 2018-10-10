#!/bin/bash

#echo "input $1"
#if [ -n "$2" ]
#then

#    for ((i=1; i<="$2"; i++))
#    do
#        echo "input $1 : $i"
#    done
#fi

name=$(bashname $0)

if [ $name = "add" ] 
then
    #echo "add : $1 + $2"
    total = $[ $1 + $2 ]
elif [ $name = "mul" ]
then
    #echo "mul $1 * $2"
    total = $[ $1 * $2 ]
fi

echo $total

