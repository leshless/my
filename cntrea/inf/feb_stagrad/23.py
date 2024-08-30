def foo(n, l):
    if n > 13:
        return 0
    if n == 12:
        return 1
    
    res = foo(n+3, False) + foo(n*2, False)
    if not l:
        res += foo(n-1, True)
    return res

print(foo(3, False))