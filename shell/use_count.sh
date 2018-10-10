#!/bin/bash

#echo "input $# param"
#echo ${!#}
#
#echo "input param $*"
#for i in $* 
#do
#    echo $i
#done

for i in $@
do
    echo $i
    if [ $i -eq 5 ]
    then
        echo "value is $i"
        break
    fi
done

shift 8
echo "input " $@
shift 4
echo $@, $*
