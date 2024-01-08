import functools

@functools.cache
def foo(n):
    if n > 42:
        return (False, 0)
    if n == 42:
        return (True, 0)
    
    f1, r1 = foo(n+1)
    f2, r2 = foo(n*2)

    if n <= 10:
        r1 += 1
    elif n <= 20:
        r1 += 2
    else:
        r1 += 3

    r2 += 10

    if f1 and f2:
        return (True, min(r1, r2))
    elif f1:
        return (True, r1)
    elif f2:
        return (True, r2)
    else:
        return (False, 0)
    

print(foo(1))