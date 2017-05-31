#!/usr/bin/env python3

import os

def check_empty(dir):
  print(dir + " is : ")
  if os.listdir(dir):
    print('not empty')
  else:
    print('empty')

check_empty('./testdir')
