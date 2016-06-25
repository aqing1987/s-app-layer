
points = int(raw_input('leading points: '))
has_ball = raw_input('the leading team has ball (yes/no): ')
seconds = float(raw_input('the remaining seconds: '))

points -= 3

if has_ball == 'yes':
    points += 0.5
else:
    points -= 0.5

if points < 0:
    points = 0

points **= 2

if points > seconds:
    print 'leading safe'
else:
    print 'leading not safe'