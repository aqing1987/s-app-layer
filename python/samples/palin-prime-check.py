
num = int(raw_input('Input integer: '))

def is_palin(num):
    num_p = 0
    num_t = num

    while num_t != 0:
        num_p = num_p * 10 + num_t % 10
        num_t /= 10

    if num == num_p:
        return True
    else:
        return False

def is_prime(num):
    for i in range(2, num):
        if num % i == 0:
            return False

    return True

if is_palin(num) and is_prime(num):
    print 'Ok'
else:
    print 'No'