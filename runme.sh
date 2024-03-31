#!/bin/bash

make 

python3 create_fileA.py

./create_my_sparse_file fileA fileB

gzip -k fileA
gzip -k fileB

gzip -cd fileB.gz | ./create_my_sparse_file fileC

./create_my_sparse_file fileA fileD 100

stat "%n %s" fileA 
stat "%n %s" fileA.gz
stat "%n %s" fileB
stat "%n %s" fileB.gz
stat "%n %s" fileC
stat "%n %s" fileD
