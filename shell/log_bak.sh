#!/bin/bash
#########################################################################
# File Name: log_bak.sh
# Author: BernieZhao
# mail: berniezhao@ezfun.cn
# Created Time: 2017年12月07日 星期四 09时38分40秒
#########################################################################

log_pwd="${HOME}/frame_exec/logs"
bak_pwd="${HOME}/server/frame/src/ezfun"

#dir=`mkdir log.$mydate.$var`
#if [ -d $dir ]; then
#    dir=``

var=0
mydate=$(date +%y%m%d)
echo "dir is exist"
var=$[ $var+1 ]
echo $var
mkdir $bak_pwd/log_bak/log.$mydate.$var && cp -R $log_pwd/* $bak_pwd/log_bak/log.$mydate.$var
