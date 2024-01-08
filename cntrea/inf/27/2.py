import sys

nums = []
for l in sys.stdin:
    nums = list(map(int, l.strip().split()))
n = len(nums)

res = 0
cur = 0
for i in range(n):
    if cur < 0:
        cur = nums[i]
    else:
        cur += nums[i]

    res = max(res, cur)

print(res)