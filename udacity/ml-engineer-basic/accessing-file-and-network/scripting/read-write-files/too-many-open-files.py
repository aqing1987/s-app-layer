files = []

for i in range(10000):
    files.append(open('./my-file.txt', 'r'))
    print(i)