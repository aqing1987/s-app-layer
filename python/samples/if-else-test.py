
score = int(raw_input('input score:'))

if score >= 60:
    print 'Passed!'
else:
    print 'Failed!'

if score >= 90:
    print 'A'
elif score >= 80:
    print 'B'
elif score >= 70:
    print 'C'
elif score >= 60:
    print 'D'
else:
    print 'E'