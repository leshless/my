import functools

@functools.cache
def foo(n, t, f):
    f = f or (n % 10 == 5)
    if n > t:
        return 0 
    if n == t:
        return f

    return foo(n*2, t, f) + foo(n+1, t, f) + foo(n+3, t, f)

print(foo(1, 234, False))

