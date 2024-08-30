def foo(x, A):
    return ((x & 20777) == 0) or ((x & 12332) != 0) or ((x & A) != 0)

for A in range(100000):
    f = True
    for x in range(100000):
        f = f and foo(x, A)
        if not f:
            break

    if f:
        print(A)
        break