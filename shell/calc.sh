#!/bin/bash
#########################################################################
# File Name: calc.sh
# Author: BernieZhao
# mail: berniezhao@ezfun.cn
# Created Time: 2017年12月04日 星期一 17时46分34秒
#########################################################################

num1=10
num2=34

#echo $[num1+num2]

var1=$(echo "scale=4; 3.44 / 5" | bc)
echo $var1
