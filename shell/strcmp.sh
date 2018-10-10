#!/bin/bash

str1="Hello"
str2="hello"
str3=""

if [ $str1 = $str2 ]
then
    echo "=="
#elif [ $str1 != $str2 ]
#then
#    echo "!="
elif [ $str1 \> $str2 ]
then
    echo ">"
elif [ $str1 \< $str2 ]
then
    echo "<"
fi

#使用字符串比较时,对大于和小于号应使用转义字符\,否则会被认为是重定向

if [ -n $str2 ] #检查字符串的长度是否非0
then
    echo "-"
else
    echo "+"
fi

if [ -z $str3 ] #检查字符串的长度是否为0
then
    echo "L"
else
    echo "V"
fi
