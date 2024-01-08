import functools

@functools.cache
def foo(s, t):
    if s > t:
        return 0
    if s == t:
        return 1
    
    return foo(s*3//2, t) + foo(s*2, t) + foo(s+1, t)


print(foo(10, 16) * foo(16, 31) * foo(31, 51))
print(foo(10, 18) * foo(18, 36) * foo(36, 51))
print(foo(10, 19) * foo(19, 29) * foo(29, 51))