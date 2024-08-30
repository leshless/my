import math

n, k = map(int, input().split())

nums = [0 for i in range(k)]
for i in range(n):
    i, x = map(int, input().split())
    nums[i] = math.ceil(x / 11)

print(nums)