n = int(input())

nums = []
for i in range(n):
    nums.append(int(input()))

nums.sort()
nums.reverse()
print(nums)

last = nums[0]
res = 1

for i in range(1, n):
    if nums[i] <= last - 4:
        last = nums[i]
        res += 1

print(res, last)