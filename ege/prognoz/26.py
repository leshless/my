f = open("./files/26.txt")
n = int(f.readline())

nums = []
for i in range(n):
    nums.append(int(f.readline()))
nums.sort()


m = n // 3

res1 = 0
for i in range(m):
    x = nums[i]
    res1 += (x*0.25 if x > 350 else x)

for i in range(m, n):
    x = nums[i]
    res1 += x

import math
res1 = math.ceil(res1)

nums.reverse()
res2 = 0
for i in range(n):
    if i % 3 == 2:
        res2 += (math.ceil(x*0.25) if x > 350 else x)
    else:
        res2 += x

print(res1, res2)