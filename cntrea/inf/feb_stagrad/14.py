import itertools

def foo(num, p):
    res = 0
    cur = 1

    for i in range(len(num)-1, -1, -1):
        res += num[i] * cur
        cur *= p

    return res

for p in range(9, 16):
    for x, y, z, w in itertools.product([i for i in range(p)], repeat=4):
        if foo([z, x, y, x, 4], p) + foo([x, y, 6, 5, 8], p) == foo([w, z, x, 7, 3], p):
            print(foo([x, y, z, w], p))