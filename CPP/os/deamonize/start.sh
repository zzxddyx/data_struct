#!/bin/bash

daemonize -a -e /home/ezfun/data_struct/CPP/os/deamonize/error.log -o /home/ezfun/data_struct/CPP/os/deamonize/output.log -p /home/ezfun/data_struct/CPP/os/deamonize/daemonize.pid -l /home/ezfun/data_struct/CPP/os/deamonize/lokfile /home/ezfun/data_struct/CPP/os/deamonize/bin -c mycfg.cfg
