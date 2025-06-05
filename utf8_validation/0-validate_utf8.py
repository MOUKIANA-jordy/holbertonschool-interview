#!/usr/bin/python3
"""
ValidUTF8 MOdule
"""


def validUTF8(data):
    """ Determines if a given data set represents a valid UTF-8 encoding.
    """
    byte_sequence = bytes([num & 0xFF for num in data])
    try:
        byte_sequence.decode('utf-8')
        return True
    except UnicodeDecodeError:
        return False
