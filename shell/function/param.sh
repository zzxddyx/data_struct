#!/bin/bash

function test(){
    #echo "Hello"
    #local param=10
    #echo $[ $param * 2 ]

    if [ $# -eq 0 ] || [ $# -gt 2 ]
    then
        echo "error"
    elif [ $# -eq 1 ]
    then
        echo $[ $1 * 2 ]
    elif [ $# -eq 2 ]
    then
        echo $[ $1 * $2 ]
    fi
}

test $1 $2

