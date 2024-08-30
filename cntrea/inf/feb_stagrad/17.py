import sys 

nums = []

for l in sys.stdin.readlines():
    nums.append(int(l))


mx = None
for x in nums:
    if x % 1000 == 238:
        if mx == None or x > mx:
            mx = x

c = 0
res = 0

for i in range(len(nums)-2):
    r5 = 0
    d3 = 0
    d5 = 0
    s = 0
    
    for j in range(3):    
        x = nums[i+j]

        if len(str(x)) == 5:
            r5 += 1
        
        if x % 3 == 0:
            d3 += 1
        
        if x % 5 == 0:
            d5 += 1

        s += x

    if (1 <= r5 <= 2) and (d3 > d5) and (s > mx):
        c += 1
        res = max(res, s)

print(c, res)

