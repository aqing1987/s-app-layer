#!/usr/bin/env python3

import sys
import hashlib

def main():
    if len(sys.argv) != 2:
        print("Usage: python3 %s string" % (__file__))
        sys.exit()

    src = sys.argv[1]
    print("string [%s] md5 is: " % (src))
    md5 = hashlib.md5()
    md5.update(src.encode('utf-8'))
    print(md5.hexdigest())

if __name__ == '__main__':
    main()
