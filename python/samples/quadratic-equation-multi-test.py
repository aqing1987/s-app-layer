# supported by python2
# ax**2 + bx + c = 0
import math

while True:
    a = float(raw_input('input coefficient a:'))
    b = float(raw_input('input coefficient b:'))
    c = float(raw_input('input coefficient c:'))

    if a != 0:
        delta = b**2 - 4*a*c
        if delta < 0:
            print 'No solution'
        elif delta == 0:
            s = -b/(2*a)
            print 's:', s
        else:
            root = math.sqrt(delta)
            s1 = (-b + root)/(2*a)
            s2 = (-b - root)/(2*a)
            print 'the solutions are: ', s1, s2
    else:
        print 'Error'

    ch = raw_input('quit?')
    if ch == 'q':
        break
