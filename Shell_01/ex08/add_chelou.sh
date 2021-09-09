#!/bin/bash

echo $FT_NBR3+$FT_NBR4 | tr "\'" "0" | tr '\\\"\?\!mrdoc' '123401234' | xargs echo "obase=13;ibase=5;" | bc | tr "0123456789ABC" "gtaio luSnemf"
