import functools

@functools.cache
def f(n):
    if n > 1_000_000:
        return n 
    return n + f(2*n)

def g(n):
    return f(n) / n 

x = g(1000)
res = 0
for n in range(1, 1_000_000):
    if g(n) == x:
        res += 1

print(res)