# if you pass the read method an integer argument, it will read up to that
# number of characters, output all of them, and keep the 'window' at that
# position ready to read on.
with open('./camelot.txt', 'r') as song:
    print(song.read(2))
    print(song.read(8))
    print(song.read())