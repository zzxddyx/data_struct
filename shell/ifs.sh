#!/bin/bash

#for entry in $(cat /etc/passwd)
#do
#    echo $entry
#    IFS=:
#    for id in $entry 
#    do
#        echo $id
#    done
#done > a

OLD_IFS=$IFS
IFS=$'\n'
for entry in $(cat ~/frame_exec/bin/ezfun/horse_race_client.lua)
do
    echo $entry
done > a
IFS=$OLD_IFS

