import math

a, b = map(int, input().split())

table = set([])
prime = set([])

for i in range(2, int(math.sqrt(b)) + 1):
    if not i in table:
        prime.add(i)
    
    for j in prime:
        if i * j > int(math.sqrt(b) + 1):
            break
        table.add(i*j)

res = set([])
for p in prime:
    x = a + (-a % p)
    while (x < b):
        if x != p:
            res.add(x)
        x += p
res.add(0)
res.add(1)

for x in range(a, b):
    if not x in res:
        print(x)