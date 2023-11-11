def foo(x, y, A):
    return (x + 2*y > 48) or (y > x) or (x + 3*y < A)

for A in range(500, 1, -1):
    for x in range(0, 501):
        for y in range(0, 501):
            if foo(x, y, A) == 0:
                print(A)
                exit()