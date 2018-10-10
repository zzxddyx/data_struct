#!/bin/bash

val=100
#while echo "=$val=" 
#    [ $val -ge 0 ]
#do
#    echo "value : $val"
#    val=$[ $val-1 ]
#done

until echo "=====$val=====" 
    [ $val -eq 10 ]
do
    echo "value : $val"
    val=$[ $val-10 ]
done
