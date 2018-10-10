#!/bin/bash

num=10
str="hello"

if [ $num = 10 ] && [ $str = "hello" ]
then
    echo "="
else
    echo "!="
fi

if (($num ** 2 > 90))
then
    echo "big"
else
    echo "little"
fi


