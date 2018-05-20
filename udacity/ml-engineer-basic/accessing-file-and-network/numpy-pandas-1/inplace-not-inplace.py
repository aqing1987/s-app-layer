# += operates in-place
# + does not

import numpy as np

a = np.array([1, 2, 3, 4, 5])

# slice refers to what's called a view of the original array.
slice = a[:3]
slice[0] = 100
print(a)