#!/usr/bin/env python3

import sys

f = open('input-data.txt', 'r')

# For a sliding window of 3 values

# Algorithm
# We can have an list of 3 integers called window
# Intialise it by populating it with the first 3 values
# Then take sum of the values in window to give us A
# This is our starting sum A
# Loop
#    Update list by replacing value at [idx] with the next value read in
#    where idx = (idx % len) - use the array in a circular fashion
#    Then take sum of the values in window to give us the next sum
#    This is sum B say
#    Check if B > A and increment count appropriately
# Loop round again

def getSum(window, len):
    sum=0
    for idx in range(len):
        sum = sum + window[idx]
    return sum

# Setup initial window (we will use it as a circular buffer)
len=3
window=[0 for idx in range(len)]
for idx in range(len):
    line = f.readline()
    if line == "":
        exit(1)
    window[idx] = int(line)

sum = getSum(window, len)
print("Initial window sum is: %d" % (sum))

idx=0
count=0
while f:
    line = f.readline()
    if line == "": # i.e. EOF reached
      break

    sum_prev = sum
    window[idx] = int(line)
    idx += 1;
    idx = (idx % len)
    sum = getSum(window, len)
 
    if (sum > sum_prev):
        count +=1
        print("%d (INCREASED)" % (sum))
    else:
        print("%d (decreased)" % (sum))
        
f.close()

print("count: %d" % count)

