import functools

@functools.cache
def foo(a, b, p):
    if a > b:
        return 0
    
    if a == b:
        return 1
    
    s = 0
    if p != 1:
        s += foo(a+1, b, 1)
        s += foo(a+2, b, 1)
    if p != 2:
        s += foo(a*2, b, 2)
        s += foo(a*3, b, 2)

    return s


print(foo(1, 22, 0))