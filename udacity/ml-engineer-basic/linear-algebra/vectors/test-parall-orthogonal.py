from vector import Vector

print('first pair...')
v = Vector([-7.579, -7.88])
w = Vector([22.737, 23.64])
print('is parallel: ',  v.is_parallel_to(w))
print('is orthogonal: ', v.is_orthogonal_to(w))

print('second pair...')
v = Vector([-2.029, 9.97, 4.172])
w = Vector([-9.231, -6.639, -7.245])
print('is parallel: ',  v.is_parallel_to(w))
print('is orthogonal: ', v.is_orthogonal_to(w))
