#!/bin/bash
file="test.sh"
for state in $(cat $file)
do
    echo $state
done

for test in Hello Java C++ C Lua
do
    echo $test
done

echo "++++++++++++++++++++++++++++++++++++++++"
for file in /home/ezfun/server/frame/src/ezfun/src/*
do
    if [ -d "$file" ]
    then
        echo "D : $file"
        for file1 in $file/* 
        do
            echo "D-F : $file1"
        done
    elif [ -f "$file" ]
    then
        echo "F : $file"
    fi
done

for ((i=1; i<10; i++))
do
    echo $i
done
