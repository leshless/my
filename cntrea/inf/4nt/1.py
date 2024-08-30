prime = []
col = [True for i in range(100,1)]

for x in range(2, 1001):
    if col[x]:
        prime.append(x)

    for p in prime:
        if p*x > 1000:
            break
        col[p*x] = False


nums = []
for p in prime:
    nums.append(2 * p**4)

a, b = map(int, input().split())
for x in nums:
    if a <= x <= b:
        print(x)