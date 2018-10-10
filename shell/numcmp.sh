#!/bin/bash
#########################################################################
# File Name: numcmp.sh
# Author: BernieZhao
# mail: berniezhao@ezfun.cn
# Created Time: 2017年12月05日 星期二 14时32分27秒
#########################################################################

testnum0=9
localnum=10

if [ $testnum0 -eq $localnum ]
then
    echo "="
#elif [ $testnum0 -ge $localnum ]
#then
#    echo ">="
#elif [ $testnum0 -gt $localnum ]
#then
#    echo ">"
#elif [ $testnum0 -le $localnum ]
#then
#    echo "<="
#elif [ $testnum0 -lt $localnum ]
#then
#    echo "<"
elif [ $testnum0 -ne $localnum ]
then
    echo "!="
fi
