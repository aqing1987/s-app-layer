# You create a list comprehension with brackets []

## extract First Names
names = ["Rick Sanchez", "Morty Smith", "Summer Smith", "Jerry Smith",
         "Beth Smith"]

first_names = [name.split()[0].lower() for name in names]
print(first_names)

## multiples of three
multiples_3 = [x * 3 for x in range(1, 21)]
print(multiples_3)

## fileter names by scores
scores = {
             "Rick Sanchez": 70,
             "Morty Smith": 35,
             "Summer Smith": 82,
             "Jerry Smith": 23,
             "Beth Smith": 98
}

passed = [name for name, score in scores.items() if score >= 65]
print(passed)
