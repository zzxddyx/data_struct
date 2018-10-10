#!/bin/bash

set -- $(getopt -q ab:cd "$@")

while [ -n "$1" ]
do
    case "$1" in 
        -a ) echo "find function a"
            ;;
        -b ) echo "param is $2"
             echo "find function b; param is $2"
             shift
             ;;
         -c ) echo "find function c"
             ;;
         -- ) shift
             break
             ;;
          * ) echo "$1 function is not found"
      esac
      shift
done

count=1
for param in "$@"
do
    echo "param#$$count : $param"
    count=$[ $count+1 ]
done
