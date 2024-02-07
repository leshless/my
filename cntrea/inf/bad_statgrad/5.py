def foo(n):
    r = bin(n)[2:]
    
    if n % 5 == 0:
        r += "101"
    else:
        r += "1"
    
    n = int(r, 2)

    if n % 7 == 0:
        r += "111"
    else:
        r += "1"

    return int(r, 2)

res = 0
for n in range(1000000):
    if (foo(n) < 1728404):
        res = n

print(res)