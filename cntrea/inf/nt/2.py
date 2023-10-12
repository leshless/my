def GCD(a, b):
    while b != 0:
        a, b = b, a % b
    return a

nums = list(map(abs, map(int, input().split())))
n = len(nums)

if (n == 0):
    print(0)    
    print(1)
    exit()

gcd = 0
for x in nums:
    gcd = GCD(gcd, x)

lcm = 1
for x in nums:
    if x != 0:
        lcm *= x // GCD(x, lcm)
    else:
        lcm = 0
        break

print(gcd, lcm)