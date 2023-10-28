def GCD(a, b):
    while b != 0:
        a, b = b, a % b
    return a

a, b, c = map(int, input().split())

if b == 0:
    if c % a != 0:
        print("NO SOLUTIONS")
        exit()
    print(f'x = {c//a} + {0}k')
    print(f'y = {0} - {1}k')  
    exit()

gcd = GCD(a, b)
if (c % gcd != 0):
    print("NO SOLUTIONS")
    exit()

a //= gcd
b //= gcd
c //= gcd

if b < 0:
    a, b, c = -a, -b, -c

p1 = [b, 0]
p2 = [a, c]

while(p2[0] != 0):
    d = p1[0] // p2[0]
    p1[0] -= d * p2[0]
    p1[1] -= d * p2[1]
    p1, p2 = p2, p1


if p1[0] < 0: p1 = [-p1[0], -p1[1]]
al = p1[1] % b
bt = b

gm = (c - a * al) // b
om = a

print(f'x = {al} + {bt}k')
print(f'y = {gm} - {om}k')