def to(n):
    r = []
    while n > 0:
        r.append(n % 3)
        n //= 3
    r.reverse()

    return r

def fr(r):
    n = 0
    for x in r:
        n = n * 3 + x 
    return n

def foo(n):
    r = to(n)
    
    if n % 4 == 0:
        r += r[-3:]
    else:
        r += to((n % 4) * 4)

    return fr(r)


res = 1
for n in range(9, 1000):
    r = foo(n)
    if r < 127:
        res = max(r, res)
print(res)