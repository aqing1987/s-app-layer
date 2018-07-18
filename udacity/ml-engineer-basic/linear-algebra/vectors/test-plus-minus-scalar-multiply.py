from vector import Vector

my_vector = Vector([1, 2, 3])
print(my_vector)

my_vector2 = Vector([1, 2, 3])
my_vector3 = Vector([-1, 2, 3])
print(my_vector == my_vector2)
print(my_vector2 == my_vector3)

v = Vector([8.218, -9.341])
w = Vector([-1.129, 2.111])
print(v.plus(w))

v = Vector([7.119, 8.215])
w = Vector([-8.223, 0.878])
print(v.minus(w))

v = Vector([1.671, -1.012, -0.318])
c = 7.41
print(v.times_scalar(c))
