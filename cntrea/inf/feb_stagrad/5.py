def foo(n):
    b = bin(n)[2:]
    
    r2 = int(b[-2:], 2)
    m2 = int(b[:-2], 2)

    r1 = int(b[-1:], 2)
    m1 = int(b[:-1], 2)

    return (m1 % 4 == r1) or (m2 % 4 == r2)

print(foo(17))

res = 0
for n in range(1_000_000_000, 1_789_456_124):
    if foo(n):
        res += 1

print(res)