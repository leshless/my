import functools

@functools.cache
def foo(n):
    if n == 25:
        return 1
    if n > 25:
        return 0
    if n == 13:
        return 0
    
    return foo(n+1) + foo(n+5) + foo(n*2)

print(foo(7))