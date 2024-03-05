import itertools

def f(x, y, z, w):
    return (x <= (y == w)) and (y == (w <= z))

for row in itertools.product((0, 1), repeat=4):
    x, y, z, w = row
    print(f"{x} {y} {z} {w} {int(f(x, y, z, w))}")