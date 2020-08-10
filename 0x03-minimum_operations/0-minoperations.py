#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):

    H = 1
    clipboard = 0
    numOper = 0
    index = 1

    if type(n) is int and n >= 2:
        while H < n:
            if n % 2 == 0:
                # logica de mitades
                if H < (n / 2):
                    clipboard = H
                    H += clipboard
                    numOper += 2
                else:
                    H += clipboard
                    numOper += 1
            else:
                # logic por multi
                if n % index == 0:
                    clipboard = H
                    H += clipboard
                    numOper += 2
                else:
                    H += clipboard
                    numOper += 1
            index += 1

        return numOper

    else:
        return 0
