def foo(x, y, z, w):
    return ((x <= y) or (z == x)) and (w <= z)


import itertools

print("x y z w")
for x, y, z, w in itertools.product((0, 1), repeat=4):
    f = int(foo(x, y, z, w))
    print(x, y, z, w, f)