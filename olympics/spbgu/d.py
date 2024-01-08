def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def burnside(n):
    res = 0 
    for i in range(n):
        res += 2 ** gcd(i, n)
    return res // n


for n in range(1, 61):
    print(n, burnside(n))    