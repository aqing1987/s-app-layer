# conveniently, python will loop over the lines of a file using the syntax
# `for line in file'

camelot_lines = []
with open("./camelot.txt", 'r') as f:
    for line in f:
        camelot_lines.append(line.strip())

print(camelot_lines)