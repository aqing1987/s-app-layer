
x = float(raw_input('Enter the number: '))
low = 0
high = x
guess = (low + high) / 2

while abs(guess ** 2 - x) > 1e-5:
    if guess ** 2 < x:
        low = guess
    else:
        high = guess
    guess = (low + high) / 2

print 'The root of x is:', guess