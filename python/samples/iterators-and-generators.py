## chunker
def chunker(iterable, size):
    """Yield successive chunks from iterable of length size."""
    for i in range(0, len(iterable), size):
        yield iterable[i:i+size]

for chunk in chunker(range(25), 4):
    print(list(chunk))

## generator expressions
# You can actually create a generator in the same way you'd normally write
# a list comprehension, except with parentheses instead of square brackets.
sq_iterator = (x**2 for x in range(10))
for sqi in sq_iterator:
    print(sqi)