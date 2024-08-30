def foo(x, a):
    return (x % a != 0) <= ((x % 14 == 0) <= (x % 4 != 0))

for a in range(1, 1000):
    f = True
    for x in range(1, 1000):
        if not foo(x, a):
            f = False
            break

    if f:
        print(a)