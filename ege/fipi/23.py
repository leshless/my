import functools

@functools.cache
def foo(n, t):
    if n == t:
        return 1
    if n > t:
        return 0
    
    return foo(n+1, t) + foo(n+2, t) + foo(n*2, t)

print(foo(4, 11) * foo(11, 13) * foo(13, 15))