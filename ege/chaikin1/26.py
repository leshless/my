import sys 

nums = []
for l in sys.stdin.readlines():
    nums.append(int(l))
nums.sort()
n = len(nums)

c = 0
res = 0
for i in range(n-2):
    for j in range(i+1, n-1):
        for k in range(j+1, n):
            if nums[i] + nums[j] <= nums[k]:
                break
            c += 1
            res = max(res, nums[i] + nums[j] + nums[k])

print(c, res)