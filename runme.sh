#!/bin/bash 

python3 create_fileA.py

make

./myprogram fileA fileB

gzip -k fileA
gzip -k fileB

gzip -cd fileB.gz | ./myprogram fileC

./myprogram fileA fileD -b 100

stat --printf "%n size is %s\n"  fileA 
stat --printf "%n size is %s\n" fileA.gz
stat --printf "%n size is %s\n" fileB.gz
stat --printf "%n size is %s\n" fileC
stat --printf "%n size is %s\n" fileD
