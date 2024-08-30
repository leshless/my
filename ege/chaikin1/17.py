import sys

nums = []
for l in sys.stdin.readlines():
    nums.append(int(l))

mx = -10000000000

for x in nums:
    if (abs(x) % 6 == 3) and ((abs(x) // 6) % 6 == 2):
        mx = max(mx, x)

print(mx)

c = 0
res = -10000000000000
for i in range(len(nums)-2):
    c4 = 0
    s = 0
    for j in range(i, i+3):
        c4 += int(1000 <= abs(nums[j]) <= 9999)
        s += nums[j]
    
    if (c4 == 1) and (s % mx == 0):
        c += 1
        res = max(res, s)
print(c, res)