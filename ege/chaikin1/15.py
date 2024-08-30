def foo(x, a):
    return (x & a != 0) or ((x & 52 == 0) and (x & 14 == 0))


for a in range(1000):
    f = True
    for x in range(10000):
        if not foo(x, a):
            f = False
            break
    if f:
        print(a)