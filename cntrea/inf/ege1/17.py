import sys

nums = []

for l in sys.stdin.readlines():
    nums.append(int(l))

m = 0
for x in nums:
    if x % 10 == 9 and (x // 10) % 10 == 1:
        m = max(m, x)

c = 0
m1 = 0
for i in range(len(nums)-2):
    x, y, z = nums[i], nums[i+1], nums[i+2]
    
    all = [x, y, z]
    c1 = 0
    for some in all:
        if some >= 1000 and some < 10000:
            c1+=1

    if (x % 3 == 0 or y % 3 == 0 or z % 3 == 0) and (x + y + z > m) and (c1==2):
        c+=1
        m1 = max(m1, x + y + z)

print(c, m1)

    