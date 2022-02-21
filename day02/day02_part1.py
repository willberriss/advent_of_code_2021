#!/usr/bin/env python3

# I did this with Harry (age 11)

import sys

assert len(sys.argv) == 2
datafile = sys.argv[1]
print("datafile: %s" % datafile)
f = open(datafile, 'r')

# Puzzle
# forward, down, up
# down INCREASES depth

# hpos  = horizontal position
# depth 

count=0
x=0
d=0
while f:
    line = f.readline()
    if line == "": # i.e. EOF reached
      break

    myline = line.strip()
    count+=1
    
    command = myline.split()

    dirt = command[0]
    dist = int(command[1])

    print("Direction: %s" % dirt )
    print("Distance: %d" % dist)

    if command[0] == "forward":
        print("Found a forward")
        x += dist
	
    if command[0] == "up":
        print("Found an up")
        d -= dist
    
    if command[0] == "down":
        print("Found a down")
        d += dist

f.close()

print("count: %d" % count)
print("x: %d" % x)
print("d: %d" % d)

answer = x * d
print("Answer: %d" % answer)


