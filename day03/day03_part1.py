#!/usr/bin/env python3

import sys

def myday3_part1(datafile):


    # Puzzle
    # Each bit in the gamma rate can be determined by finding the most common bit in the corresponding position
    # So, the gamma rate is the binary number 10110, or 22 in decimal.
    # The epsilon rate is calculated in a similar way; rather than use the 
    # most common bit, the least common bit from each position is used. 
    # So, the epsilon rate is 01001, or 9 in decimal. 
    # Multiplying the gamma rate (22) by the epsilon rate (9) produces the power consumption, 198.

    print("Opening file: %s" % datafile)
    f = open(datafile, 'r')
    line = f.readline()
    myline = line.strip()
    mylist = list(myline)
    N = len(mylist)
    print("N = %d" % N)
    f.close()
    
    count = 0;
    mysum = [0] * N

    mcb = ["0"] * N
    lcb = ["0"] * N

    # 
    # Count the total number of elements (rows)
    # Count the number of 1s = sum
    # The number of 0s = (count - sum)
    #
    print("Opening file: %s" % datafile)
    f = open(datafile, 'r')
    while f:
        line = f.readline()
        if line == "": # i.e. EOF reached
          break

        myline = line.strip()
        #print("myline = %s" % myline)
        count += 1
        
        mylist = list(myline)

        # There are N digits, positions 0 .. N-1
        for pos in range(N):
            mysum[pos] += int(mylist[pos])

    f.close()

    print("count: %d" % count)

    # mcb = most common bit
    for pos in range(N):
        print("mysum[%d] = %d" % (pos, mysum[pos]))
        if mysum[pos] >= count/2:
            mcb[pos] = "1"
        else:
            lcb[pos] = "1"

    #for pos in range(N):
    #    print("mcb[%d] = %s" % (pos, mcb[pos]))

    #for pos in range(N):
    #    print("lcb[%d] = %s" % (pos, lcb[pos]))

    gamma_binary = "".join(mcb)
    epsilon_binary = "".join(lcb)

    print("gamma_binary = %s" % gamma_binary)
    print("epsilon_binary = %s" % epsilon_binary)

    gamma_rate = int(gamma_binary, 2)
    epsilon_rate = int(epsilon_binary, 2)

    print("gamma_rate = %s" % gamma_rate)
    print("epsilon_rate = %s" % epsilon_rate)

    power_consumption = gamma_rate * epsilon_rate

    return power_consumption


if __name__ == '__main__':
    print("We've been called directly, not imported.")
    assert len(sys.argv) == 2
    datafile = sys.argv[1]
    print("datafile: %s" % datafile)
    power_consumption = myday3_part1(datafile)
    print("power_consumption = %d" % power_consumption)

