def foo(x, y, a):
    return ((x > 68) or (y > 89)) or (2*x - 7*y < a)

for a in range(-100, 200):
    f = True
    for x in range(100):
        for y in range(100):
            if not foo(x, y, a):
                f = False
                break

        if not f:
            break
    
    if f:
        print(a)