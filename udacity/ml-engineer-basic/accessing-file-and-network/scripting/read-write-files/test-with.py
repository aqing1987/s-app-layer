# with keyword allows you to open a file, do operations on it, and
# automatically close it after the indented code is executed.
with open('./my-file.txt', 'r') as f:
    file_data = f.read()

print(file_data)