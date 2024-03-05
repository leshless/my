def foo(x, A):
    return (72 % x != 0) or (120 % x != 0) or (A - x > 100)

for A in range(1000):
    f = True
    for x in range(1, 1000):
        if not foo(x, A):
            f = False
            break
    
    if f:
        print(A)