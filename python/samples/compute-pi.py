
# pi = 4(1- 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ... + (-1)^(i+1)/(2i-1))

# method 1:
pi = 0

for i in range(1, 100000):
    pi += (-1.0)**(i+1)/(2*i-1)

pi *= 4
print 'method 1 - pi =', pi

# method 2:
pi = 0
sign = 1
divisor = 1

for i in range(1, 100000):
    pi += 4.0*sign/divisor
    sign *= -1
    divisor += 2

print 'method 2 - pi =', pi