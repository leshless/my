import functools

@functools.cache
def foo(n, t):
    if n > t:
        return 0
    if n == t:
        return 1
    
    return foo(n+1, t) + foo(n+2, t) + foo(n*3, t)

t = int(input())
print(foo(1, t))

