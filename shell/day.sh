#!/bin/bash
#########################################################################
# File Name: day.sh
# Author: BernieZhao
# mail: berniezhao@ezfun.cn
# Created Time: 2017年12月04日 星期一 10时51分10秒
#########################################################################

test=date
echo $test

mydate=$(date +%y%m%d%h)
echo $mydate

MY_HOME="/home/ezfun/server/frame/src/ezfun/src"
ls -l $MY_HOME > log.$mydate


