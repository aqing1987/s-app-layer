
# e = 1 + 1/1! + 1/2! + 1/3! ... + 1/n!

# method 1:
import math

e = 1
for i in range(1, 100):
    e += 1. / math.factorial(i)

print 'method 1 - e =', e

# method 2:
e = 1
factorial = 1
for i in range(1, 100):
    factorial *= i
    e += 1. / factorial

print 'method 2 - e =', e