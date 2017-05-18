#!/usr/bin/env python3

import hashlib
import time
import sys

class Md5Crack:

  def __init__(self, crack_str):
    self.chars="ABCDEFGHIJKLMNOPQRSTUVWXYZ"\
      "abcdefghijklmnopqrstuvwxyz"\
      "1234567890"\
      " ."
    self.crack_str = crack_str
    self.cdict = {
      'c1':'', 'c2':'', 'c3':'', 'c4':'',
      'c5':'', 'c6':'', 'c7':'', 'c8':'',
      'c9':'', 'c10':'',
    }
    self.full=""
    self.finish=False

  def compare(self, plain):
    md5val = hashlib.md5(plain).hexdigest()
    if md5val == self.crack_str:
      print("\n\t******************************************\n")
      print("\t*** " + md5val + ":[" + plain + "]\n")
      print("\t******************************************\n")
      return True
    else:
      print(plain + ":" + md5val + " - N")
      return False

  def plain_code_guess(self, digits):
    if self.finish == True:
      return

    if digits == 0:
      self.full = self.cdict['c10'] + self.cdict['c9'] + self.cdict['c8'] +\
                  self.cdict['c7'] + self.cdict['c6'] + self.cdict['c5'] + \
                  self.cdict['c4'] + self.cdict['c3'] + self.cdict['c2'] + \
                  self.cdict['c1']

      plain = self.full
      if self.compare(plain) == True:
        self.finish = True
      return
    else:
      sc = 'c' + str(digits)
      digits -= 1
      for c in self.chars:
        self.cdict[sc] = c
        self.plain_code_guess(digits)

def main():
  try:
    if len(sys.argv) != 2:
      print("Usage: python3 %s md5val" % (__file__))
      sys.exit()

    if len(sys.argv[1]) != 32:
      print(len(sys.argv[1]))
      print("invalid md5 value")
      sys.exit()

    md5v = sys.argv[1]
    print("\n\tYour MD5 value is " + md5v)
    print("\tNote: At most 10 plain characters can be cracked now.")
    flag = raw_input("\n\tInput y to continue, n to stop (y/n): ")
    if flag == 'y' or flag == 'Y':
      print("-------------- cracking ---------------\n")
    else:
      sys.exit()

    start = time.time()
    obj = Md5Crack(md5v)
    for i in range(1, 11):
      obj.plain_code_guess(i)
    if obj.finish == False:
      print("\n\t*** Plain code not found! ***\n")
    end = time.time()
    print("used: %f seconds" % (end - start))
  except KeyboardInterrupt:
    print("Bye!")

if __name__ == "__main__":
  main()
