import sys 

nums = [int(l) for l in sys.stdin.readlines()]

mn = 1000000
for x in nums:
    if (abs(x) % 10 == 7):
        mn = min(x, mn)


c = 0
mx = -10000
for i in range(len(nums) - 1):
    x = nums[i]
    y = nums[i+1]
    
    if (abs(x) % 10 == 7) != (abs(y) % 10 == 7) and (x*x + y*y < mn*mn):
        c += 1
        mx = max(mx, x*x + y*y)

print(c, mx)
