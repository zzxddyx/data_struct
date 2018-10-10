#!/bin/bash
#########################################################################
# File Name: test.sh
# Author: BernieZhao
# mail: berniezhao@ezfun.cn
# Created Time: 2017年12月04日 星期一 20时36分16秒
#########################################################################

if test
then
    echo "True"
else
    echo "False"
fi

testnum=10
if test 10=$testnum
then
    echo "True"
else
    echo "False"
fi

string="Fuck"
if [ string=$string ]
then
    echo "equal"
else
    echo "not"
fi
