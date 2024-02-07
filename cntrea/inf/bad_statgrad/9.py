import math

def c1(nums):
    m = max(nums)
    return (nums.count(m) == 1)

def c2(nums):
    return len(set(nums)) < len(nums)

def c3(nums):
    nums = sorted(nums)
    n = len(nums)
    return nums[n-1] > 3 * sum(nums[:n-1]) / (n-1)

res = 0
f = open("./files/9.txt")
for l in f.readlines():
    nums = list(map(int, l.split()))
    if c1(nums) and c2(nums) and c3(nums):
        res += 1

print(res)