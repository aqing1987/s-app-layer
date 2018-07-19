from vector import Vector

print('#1 cross')
v = Vector([8.462, 7.893, -8.187])
w = Vector([6.984, -5.975, 4.778])
print(v.cross(w))

print('#2 area of parallelogram')
v = Vector([-8.987, -9.838, 5.031])
w = Vector([-4.268, -1.861, -8.866])
print(v.area_parallelogram(w))

print('#3 area of triangle')
v = Vector([1.5, 9.547, 3.691])
w = Vector([-6.007, 0.124, 5.772])
print(v.area_triangle(w))
