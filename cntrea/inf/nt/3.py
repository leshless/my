def binpow(a, n, m):
    res = 1
    while n > 0:
        if (n & 1):
            res *= a
            n -= 1
        else:
            a *= a
            n //= 2
        a %= m
        res %= m
    
    return res


def pow(a, n, m):
    if n == 0: return 1%m
    root = pow(a, n//2, m)
    if n % 2 == 0: return root*root%m
    else: return root*root*a%m
        


a, b, n = map(int, input().split())
print(pow(a, b, n))