
num = int(raw_input('input integer: '))

num_bk = num
num_p = 0

# inverse
while num != 0:
    num_p = num_p * 10 + num % 10
    num /= 10

if num_bk == num_p:
    print 'palindrome number'
else:
    print 'not palin number'