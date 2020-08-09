#!/usr/bin/python3
"""
Minimum Operations
"""


def esPar(x):
    return x % 2 == 0


def minOperations(n):

    fileText = 'H'
    clipboard = ''
    numOper = 0
    index = 1

    if type(n) is int:
        while len(fileText) < n:
            if esPar(n):
                # logica de mitades
                if len(fileText) < (n / 2):
                    clipboard = fileText
                    fileText += clipboard
                    numOper += 2
                else:
                    fileText += clipboard
                    numOper += 1
            else:
                # logic por multi
                if n % index == 0:
                    clipboard = fileText
                    fileText += clipboard
                    numOper += 2
                else:
                    fileText += clipboard
                    numOper += 1
            index += 1

        return numOper

    else:
        return 0
