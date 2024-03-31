#!/bin/bash 

python3 create_fileA.py

make

./myprogram fileA fileB

gzip -k fileA
gzip -k fileB

gzip -cd fileB.gz | ./myprogram fileC

./myprogram fileA fileD -b 100

stat "%n %s" fileA 
stat "%n %s" fileA.gz
stat "%n %s" fileB
stat "%n %s" fileB.gz
stat "%n %s" fileC
stat "%n %s" fileD
