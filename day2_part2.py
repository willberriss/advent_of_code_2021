#!/usr/bin/env python3

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
# aim

# down X increases your aim by X units.
# up X decreases your aim by X units.
# forward X does two things:
# It increases your horizontal position by X units.
# It increases your depth by your aim multiplied by X.

count=0
hpos=0
depth=0
aim=0
while f:
    line = f.readline()
    if line == "": # i.e. EOF reached
      break

    myline = line.strip()
    count+=1
    
    command = myline.split()

    direction = command[0]
    distance = int(command[1])

    print("Direction: %s" % direction)
    print("Distance: %d" % distance)

    if direction == "up":
        aim -= distance 
    
    if direction == "down":
        aim += distance 
    
    print("Aim: %d" % aim)
    
    if direction == "forward":
        hpos += distance
        depth += (aim * distance)
	    
f.close()

print("count: %d" % count)
print("hpos: %d" % hpos)
print("depth: %d" % depth)

answer = hpos * depth
print("Answer: %d" % answer)

