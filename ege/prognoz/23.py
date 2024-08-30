def foo(n, t, b):
    if n == t:
        return 1
    if n > t:
        return 0
    if n == b:
        return 0
    
    return foo(n+1, t, b) + foo(n+2, t, b) + foo(n*3, t, b)

print(foo(6, 15, 21) * foo(15, 25, 21) + foo(6, 21, 15) * foo(21, 25, 15))