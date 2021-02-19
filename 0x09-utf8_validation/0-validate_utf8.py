#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """That determines if a given data set represents a valid UTF-8 encoding"""
    bytes = 0
    for number in data:
        binary = format(number, '#010b')[-8:]
        if bytes == 0:
            for bit in binary:
                if bit == '0':
                    break
                bytes += 1
            if bytes == 0:
                continue
            if bytes == 1 or bytes > 4:
                return False
        else:
            if not (binary[0] == '1' and binary[1] == '0'):
                return False
        bytes -= 1
    return bytes == 0
