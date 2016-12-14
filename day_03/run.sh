#!/bin/bash

cat input.txt | awk '$1+$2>$3 && $2+$3>$1 && $3+$1>$2' | wc -l
cat input.txt | awk '{ for(i=0;i<3;++i) val[i,NR%3]=$(i+1); if(NR%3==0) { for(i=0;i<3;++i) print val[i,0], val[i,1], val[i,2]  }}'  | awk '$1+$2>$3 && $2+$3>$1 && $3+$1>$2' | wc -l
