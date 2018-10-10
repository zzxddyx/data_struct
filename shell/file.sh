#!/bin/bash

path_file="~/server/frame/src/ezfun/src/horse_race_client.lua"

if [ -e $path_file ] 
then
    echo "$path_file is dir"
    cd $path_file
    ls
else
    echo "$path_file not dir"
fi



