def foo(A, x):
    return ((x&A == 0) and (x&58 != 0)) <= (x&34 != 0)

for A in range(1, 100):
    f = True
    for x in range(0, 1000):
        f = f and foo(A, x)
    
    if f:
        print(A)