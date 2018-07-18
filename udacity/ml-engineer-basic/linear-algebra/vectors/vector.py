from math import sqrt, acos, pi
from decimal import Decimal, getcontext

getcontext().prec = 30

class Vector(object):

    CANNOT_NORMALIZE_ZERO_VECTOR_MSG = 'Cannot normalize the zero vector'
    
    def __init__(self, coordinates):
        try:
            if not coordinates:
                raise ValueError
            self.coordinates = tuple([Decimal(x) for x in coordinates])
            self.dimension = len(self.coordinates)

        except ValueError:
            raise ValueError('The coordinates must be nonempty')
        except TypeError:
            raise TypeError('The coordinates must be an iterable')

    def plus(self, v):
        new_coordinates = [x+y for x, y in zip(self.coordinates, v.coordinates)]
        return Vector(new_coordinates)

    def minus(self, v):
        new_coordinates = [x-y for x, y in zip(self.coordinates, v.coordinates)]
        return Vector(new_coordinates)

    def times_scalar(self, c):
        new_coordinates = [Decimal(c)*x for x in self.coordinates]
        return Vector(new_coordinates)

    def magnitude(self):
        coordinates_squared = [x**2 for x in self.coordinates]
        return sqrt(sum(coordinates_squared))

    def normalized(self):
        try:
            magnitude = self.magnitude()
            return self.times_scalar(1./magnitude)
        except ZeroDivisionError:
            raise Exception('Cannot normalize the zero vector')

        #mag = self.magnitude()
        #new_coordinates = [x/mag for x in self.coordinates]
        #return Vector(new_coordinates)

    def dot(self, v):
        return sum([x*y for x, y in zip(self.coordinates, v.coordinates)])

    def angle_with(self, v, in_degrees=False):
        try:
            u1 = self.normalized()
            u2 = v.normalized()
            angle_in_radians = acos(u1.dot(u2))

            if in_degrees:
                degrees_per_radians = 180. / pi
                return angle_in_radians * degrees_per_radians
            else:
                return angle_in_radians

        except Exception as e:
            if str(e) == self.CANNOT_NORMALIZE_ZERO_VECTOR_MSG:
                raise Exception('Cannot compute an angle with the zero vector')
            else:
                raise e
    
    # The str function gives us the ability to print out the
    # coordinates of the vector using Python's built in print
    # function
    def __str__(self):
        return 'Vector: {}'.format(self.coordinates)

    def __eq__(self, v):
        return self.coordinates == v.coordinates

# my_vector = Vector([1, 2, 3])
# print(my_vector)

# my_vector2 = Vector([1, 2, 3])
# my_vector3 = Vector([-1, 2, 3])
# print(my_vector == my_vector2)
# print(my_vector2 == my_vector3)

# v = Vector([8.218, -9.341])
# w = Vector([-1.129, 2.111])
# print(v.plus(w))

# v = Vector([7.119, 8.215])
# w = Vector([-8.223, 0.878])
# print(v.minus(w))

# v = Vector([1.671, -1.012, -0.318])
# c = 7.41
# print(v.times_scalar(c))

## 2
# v = Vector([-0.221, 7.437])
# print(v.magnitude())

# v = Vector([8.813, -1.331, -6.247])
# print(v.magnitude())

# v = Vector([5.581, -2.136])
# print(v.normalized())

# v = Vector([1.996, 3.108, -4.554])
# print(v.normalized())

#v = Vector([0, 0])
#print(v.normalized())

v = Vector([7.887, 4.138])
w = Vector([-8.802, 6.776])
print(v.dot(w))

v = Vector([3.183, -7.627])
w = Vector([-2.668, 5.319])
print(v.angle_with(w))

v = Vector([7.35, 0.221, 5.188])
w = Vector([2.751, 8.259, 3.985])
print(v.angle_with(w, in_degrees=True))

