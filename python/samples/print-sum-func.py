
def print_sum(start, stop):
    """
    To calculate the sum from start to stop
    """
    result = 0
    for i in range(start, stop+1):
        result += i
    print 'sum is ', result

print_sum(1, 100)