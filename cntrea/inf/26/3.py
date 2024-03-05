import sys 

def foo(row, k):
    n = len(row)
    res = 1
    prev = row[0]

    for i in range(1, n):
        if row[i] - row[i-1] - 1 > k:
            prev = row[i]
        else:
            res = max(res, row[i] - prev + 1)

    return res



nums = list(map(int, sys.stdin.read().split()))

k = nums[0]
n = len(nums)

rows = {}

for i in range(1, n, 2):
    y = nums[i]
    x = nums[i+1]

    if not y in rows:
        rows[y] = set()
    
    rows[y].add(x)

r1 = -1
r2 = -1


for y in rows:
    row = rows[y]
    res = foo(sorted(list(row)), k)

    if res > r1:
        r1 = res
        r2 = y
    
    if res == r1:
        r2 = max(r2, y)

print(r1, r2)

# 4_5_7_11_13_14_17 1