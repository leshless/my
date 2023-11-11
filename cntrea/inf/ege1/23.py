def foo(s, t):
    if s == 12:
        return 0
    
    if s > t:
        return 0
    
    if s == t:
        return 1
    
    return foo(s+1, t) + foo(s*2, t) + foo(s*s, t)

print(foo(3, 25))
    
