#!/bin/bash

cat /etc/passwd | sed '/^#/d' | awk "NR%2==0" | cut -d":" -f1 | rev | sort -r | awk -v F1="$FT_LINE1" -v F2="$FT_LINE2" "NR >= F1 && NR <= F2" | tr "\n" " " | sed -e "s/ /, /g" | sed "s/, \$/./g" | tr -d "\n"
