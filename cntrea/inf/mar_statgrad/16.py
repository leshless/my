n = 89999

divs = []
for i in range(2, n+1):
    while n % i == 0:
        divs.append(i)
        n //= i

res = 10000000
for m in range(16):
    a = 1
    b = 1

    for i in range(4):
        if m & (1 << i):
            a *= divs[i]
        else:
            b *= divs[i]
    
    if a > b:
        a, b = b, a
    print(a, b)
    res = min(res, b)
print(res)