import sys


nums = []
for l in sys.stdin.readlines():
    nums.append(int(l))

mn = min([x for x in nums if x % 19 == 0])

c = 0
res = 0
for i in range(len(nums)-1):
    if (nums[i] % mn == 0) or (nums[i+1] % mn == 0):
        c += 1
        res = max(res, nums[i] + nums[i+1])

print(c, res)