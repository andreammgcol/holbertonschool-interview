#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):

    H = 1
    clipboard = 0
    numOper = 0

    if type(n) is int and n >= 2:
        while H < n:
            if n % H == 0:
                clipboard = H
                H += clipboard
                numOper += 2
            else:
                H += clipboard
                numOper += 1
        return numOper
    else:
        return 0
