import itertools

def f(row):
    x, y, z, w = row 
    return ((x == y) <= ((not z) or w)) == (not((w <= x) or (y <= z)))

print("x y z w f")
for row in itertools.product([0, 1], repeat=4):
    x, y, z, w = row
    if f(row):
        print(x, y, z, w, int(f(row)))