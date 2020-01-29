#!/bin/bash

#awk {"print $1"} /Users/jasonj/github/codelab/base/scripts/textplayer/data.txt | sort
#awk {"print $1"} data.txt | sort
#awk {"print $1"} /Users/jasonj/github/codelab/base/scripts/textplayer/data.txt | sort
#awk {"print $1"} data.txt | sort
#awk 'END{print NR}' data.txt
#awk '{total=total+NF};END{print total}' data.txt
#awk 'NR==12' data.txt
#awk 'length>32' data.txt
#awk '/Pss/{getline;print}' data.txt
#awk '/Rss/{n++};END{print n}' data.txt
#awk 'BEGIN { for(i=1;i<=6;i++) print "square of", i, "is",i*i; }'
#awk -F ss '{print $0}' data.txt
#awk 'NR==1,NR==2 {print NR,$0}' data.txt
awk '{ if (length($0) > max) max = length($0) } END { print max}' data.txt
