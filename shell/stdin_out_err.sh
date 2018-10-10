#!/bin/bash

exec 2>testerr

echo "ezfun"
echo "hello lua"
echo "I want go home"

exec 1>testout
echo "This is test line"
