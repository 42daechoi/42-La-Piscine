#!/bin/bash

ifconfig -a ether | grep ether | grep -v media  | cut -d" " -f2
