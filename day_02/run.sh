#!/bin/sh
clang main.cpp -std=c++1y && strings a.out  | awk -v FS=\| '{print "first answer: " $2 "\nsecond answer: " $3;}'
