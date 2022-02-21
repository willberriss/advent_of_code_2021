#!/usr/bin/env python3

import sys
 
# Using readlines()
file1 = open('input-data.txt', 'r')
Lines = file1.readlines()

line_num=0 
count = 0
depth=2**31
print("start depth: %d" % (depth))
for line in Lines:
    # Strips the newline character
    d = int(line.strip())

    if d > depth:
    	print("%d: %d (INCREASED)" % (line_num, d))
    	count += 1
    else:
    	print("%d: %d (decreased)" % (line_num, d))

    depth=d
    line_num += 1

print("count: %d" % count)

