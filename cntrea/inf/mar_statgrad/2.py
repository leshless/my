def foo(x, y, z, w):
    return ((x or y) <= (y and z)) and ((w == x) or (w <= (not z)))

import itertools

print("z x y wf")
for row in itertools.product((0, 1), repeat=4):
    x, y, z, w = row 
    r = int(foo(x, y, z, w))
    if r == 1:
        print(z, x, y, w, r)