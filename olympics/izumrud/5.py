def foo(n, t):
    if n > t:
        return 0
    if n == t:
        return 1
    
    return foo(n+10, t) + foo(n+1, t)

print(foo(1, 24))