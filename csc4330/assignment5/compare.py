#!/usr/bin/env python

import random

all_choices = sorted(
    [513, 44, 97, 1896, 351, 10, -545, 32, 816, -902, 491,
     956, -243, -773, 84, 390])

def do_compare():
    val = random.choice(all_choices)

    comps = 0
    for choice in all_choices:
        comps = comps + 1
        if val == choice:
            return comps

def bin_search():
    val = random.choice(all_choices)
    comps = 0

    low = 0
    high = len(all_choices) - 1
    while low <= high:
        comps = comps + 1
        if val == all_choices[low]:
            return comps
        comps = comps + 1
        if val == all_choices[high]:
            return comps

        low = low + 1
        high = high - 1


comps = []
bin_search()
for _ in xrange(0, 10000):
    comps.append(bin_search())
    #comps.append(do_compare())
print comps

print sum(comps) / len(comps)
