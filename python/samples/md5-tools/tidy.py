#!/usr/bin/env python

dict_file = "aa.txt"
out_file = "common-dict.txt1"

def main():
  ftw = open(out_file, "w")

  with open(dict_file) as fileobj:
    for line in fileobj:
      line = line.strip()
      words = line.split(" ")
      for word in words:
        word = word.strip()
        if word.isdigit() == False:
          ftw.write(word + "\n")

  ftw.close()

if __name__ == "__main__":
  main()