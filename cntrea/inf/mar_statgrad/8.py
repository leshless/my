import functools

@functools.cache
def foo(x, n):
    if n == 0:
        return 1

    res = 0
    for y in range(8):
        conc = bin(x)[2:].zfill(3) + bin(y)[2:].zfill(3)

        if ((x + y) % 2 == 1) and (not "111" in conc):
            res += foo(y, n-1)
    
    return res 

res = 0
for x in range(1, 8):
    if (not "111" in bin(x)[2:]):
        res += foo(x, 15)
print(res)