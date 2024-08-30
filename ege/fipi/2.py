import itertools

def foo(x, y, z, w):
    return not(x <= z) or (y == w) or y

print("x y z w f")
for x, y, z, w in itertools.product((0, 1), repeat=4):
    f = foo(x, y, z, w)
    if not f:
        print(x, y, z, w, int(f))