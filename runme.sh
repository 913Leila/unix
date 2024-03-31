#!/bin/bash 

python3 create_fileA.py

make

./myprogram fileA fileB

gzip -k fileA
gzip -k fileB

gzip -cd fileB.gz | ./myprogram fileC

./myprogram fileA fileD -b 100

stat fileA 
stat fileA.gz
stat fileB
stat fileB.gz
stat fileC
stat fileD
