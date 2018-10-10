#!/bin/bash

echo "================"
while [ -n "$1" ]
do
    case "$1" in
        a ) echo "find a, param is : $2"
            shift
            ;;
        b ) echo "find b, param is : $2"
            shift
            ;;
        c ) echo "find c"
            ;;
        -- ) shift
            break
            ;;
        * ) echo "not find"
            ;;
    esac
    shift
done

count=1
for param in $@
do
    echo "Param #$count : $param"
    count=$[$count+1]
done

