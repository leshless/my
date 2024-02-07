import itertools

def f1(row):
    x, y, z, w = row 
    return int((x or (not y)) <= (w == z))

def f2(row):
    x, y, z, w = row 
    return int((x or (not y)) == (z <= w))


# for ord in itertools.permutations("xyzw"):
print(" x  y  z  w  1 2")
for row in itertools.product((0, 1), repeat = 4):
    if (not f1(row)) or (not f2(row)):
        print(row, f1(row), f2(row))