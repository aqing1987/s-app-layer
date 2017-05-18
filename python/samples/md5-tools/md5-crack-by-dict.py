#!/usr/bin/env python3

import hashlib
import sys

dict_file = "common-dict.txt"

def main():
  if len(sys.argv) != 2:
    print("Usage: python3 %s string" % (__file__))
    sys.exit()

  hash_to_crack = sys.argv[1]

  with open(dict_file) as fileobj:
    for line in fileobj:
      line = line.strip()
      if hashlib.md5(line).hexdigest() == hash_to_crack:
        print "\n %s:[%s]\n" % (hash_to_crack, line)
        return 0
  print "Crack Failed."

if __name__ == "__main__":
  main()