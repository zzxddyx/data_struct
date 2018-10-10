#!/bin/bash

#echo "Enter you Name"
#read Name
#echo "You Name Is : $Name"

#read -p "Enter you name : " name
#echo "You Name Is : $name"

#read -p "enter you age : " age
#day=$[ $age * 365]
#echo "你总共活了$day天"

#if read -t 5 -p "Enter you age :" age
#then
#    day=$[ $age * 365 ]
#    echo "you life is : $day"
#else
#    echo "error"
#fi

read -t 5 -n1 -s -p "Do You Want To COntinue [(Y/y)/(N/n)] ?" answer
case $answer in
    y | Y ) echo "->"
        ;;
    n | N ) echo "<-"
        exit
        ;;
esac

count=1
cat for.sh | while read line
do
    echo "Line is $count : $line"
    count=$[ $count+1 ]
done
        
