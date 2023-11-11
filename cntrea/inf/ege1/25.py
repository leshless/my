res = []

for x in range(10):
    for y in range(1000):
        n = int("3" + str(x) + "6906" + str(y) + "4")
        if n % 2024 == 0:
            res.append(n)

res.sort()
for x in res:
    print(x)