import functools

@functools.cache
def foo(n, c):
    if n > 19:
        return 0
    if c > 4:
        return 0
    if n == 19:
        return 1
    
    c += int(n % 2 == 0)
    return foo(2*n, c) + foo(n+1, c)

print(foo(1, 0))