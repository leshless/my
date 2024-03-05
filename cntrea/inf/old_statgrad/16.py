import math

res = 0
for x in range(123456795, 1234567889):
    if math.gcd(x, 14) == 1:
        res += 1

print(res)