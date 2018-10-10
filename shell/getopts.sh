#!/bin/bash

while getopts :ab:c:d:ef opt
do
    case "$opt" in
        a ) echo "function a find" 
            ;;
        b ) echo "function b find : param is $OPTARG"
            ;;
        c ) echo "function c find : param is $OPTARG"
            ;;
        d ) echo "function c find : param is $OPTARG"
            ;;
        e ) echo "function d find"
            ;;
        f ) echo "function f find"
            ;;
        * ) echo "$opt is bad function"
            ;;
    esac
done

shift $[ $OPTIND - 1 ]

count=1
for param in "$@"
do 
    echo "param#$count : $param"
    count=$[ $count+1 ]
done
