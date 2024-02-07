import functools

ban = [11, 15]

@functools.cache
def foo(n, t):
    if n == t:
        return 1
    if (n in ban) or (n > t):
        return 0
    
    return foo(n+1, t) + foo(n+3, t) + foo(n*2, t)

print(foo(2, 8) * foo(8, 20))