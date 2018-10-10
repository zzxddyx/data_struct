#!/bin/bash
#########################################################################
# File Name: stopall.sh
# Author: BernieZhao
# mail: berniezhao@ezfun.cn
# Created Time: 2017年12月04日 星期一 18时06分09秒
#########################################################################

echo "killall beam.smp node luajit beam"
killall beam.smp node luajit beam epmd

echo "OK"
