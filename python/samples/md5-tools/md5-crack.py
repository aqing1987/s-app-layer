#!/usr/bin/env python

import hashlib
import random
import itertools
import time

chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"
caracters = []
crack_str = "30b13f03cd4f95862071772cd26aaa75"
#crack_str = "fad6f4e614a212e80c67249a666d2b09"

def compare(full):
  md5val = hashlib.md5(full).hexdigest()
  if md5val == crack_str:
    print "\n\t******************************************\n"
    print "\t*** " + crack_str + ":" + full + "\t\n"
    print "\t******************************************\n"
    return True
  else:
    print full + ":" + md5val + " - N"
    return False

def digits1_guess():
  for full in chars:
    if compare(full) == True:
      return True

def digits2_guess():
  for c1 in chars:
    for c2 in chars:
      full = c1 + c2
      if compare(full) == True:
        return True

def digits3_guess():
  for c1 in chars:
    for c2 in chars:
      for c3 in chars:
        full = c1 + c2 + c3
        if compare(full) == True:
          return True
  return False

def digits4_guess():
  for c1 in chars:
    for c2 in chars:
      for c3 in chars:
        for c4 in chars:
          full = c1 + c2 + c3 + c4
          if compare(full) == True:
            return True

def digits5_guess():
  for c1 in chars:
    for c2 in chars:
      for c3 in chars:
        for c4 in chars:
          for c5 in chars:
            full = c1 + c2 + c3 + c4 + c5
            if compare(full) == True:
              return True

def digits6_guess():
  for c1 in chars:
    for c2 in chars:
      for c3 in chars:
        for c4 in chars:
          for c5 in chars:
            for c6 in chars:
              full = c1 + c2 + c3 + c4 + c5 + c6
              if compare(full) == True:
                return True

def digits7_guess():
  for c1 in chars:
    for c2 in chars:
      for c3 in chars:
        for c4 in chars:
          for c5 in chars:
            for c6 in chars:
              for c7 in chars:
                full = c1 + c2 + c3 + c4 + c5 + c6 + c7
                if compare(full) == True:
                  return True

def digits8_guess():
  for c1 in chars:
    for c2 in chars:
      for c3 in chars:
        for c4 in chars:
          for c5 in chars:
            for c6 in chars:
              for c7 in chars:
                for c8 in chars:
                  full = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8
                  if compare(full) == True:
                    return True

def main():
  try:
    start = time.time()
    if digits1_guess() == True:
      return 0
    if digits2_guess() == True:
      return 0
    if digits3_guess() == True:
      return 0
    if digits4_guess() == True:
      return 0
    if digits5_guess() == True:
      return 0
    if digits6_guess() == True:
      return 0
    if digits7_guess() == True:
      return 0
    if digits8_guess() == True:
      return 0

    end = time.time()
    print "used: %f seconds" % (end - start)
  except KeyboardInterrupt:
    print "Bye!"

if __name__ == "__main__":
  main()
