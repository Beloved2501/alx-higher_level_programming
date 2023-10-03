#!/usr/bin/python3
def uppercase(str):
    for char in str:
        if ord(char) <= ord('z') and ord(char) >= ord('a'):
            char = chr(ord(char) - 32)
        else:
            ch = char
            print("{:s}".format(ch), end="")
        print('')
