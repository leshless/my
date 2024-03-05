import functools

@functools.cache
def foo(n):
    if n == 40:
        return 1
    
    if (n > 49) or (n % 10 == 3) or (n // 10 == 3):
        return 0
    
    return foo(n+1) + foo(n*2)

print(foo(1))