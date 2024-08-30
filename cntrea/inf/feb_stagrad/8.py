import functools

@functools.cache
def foo(k, n):
    if n == 0:
        return 1
    
    nbs = []
    for x in range(9):
        if (x < k) and ((x+k) % 2 == 1):
            nbs.append(x)
        if (x > k) and ((x+k) % 2 == 0):
            nbs.append(x)

    res = 0
    for x in nbs:
        res += foo(x, n-1)
    
    return res

res = 0
for x in range(1, 9):
    res += foo(x, 11)
print(res)