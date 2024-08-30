import sys 

seq = []
for l in sys.stdin.readlines():
    seq.append(int(l))
n = len(seq)

def countr(nums, r):
    res = 0
    for x in nums:
        if len(str(x)) == r:
            res += 1
    return res

def countd(nums, d):
    res = 0
    for x in nums:
        if x % d == 0:
            res += 1
    return res

mn = 10000000000
mx = -1
for x in seq:
    if x % 1000 == 652:
        mn = min(mn, x)
        mx = max(mx, x)

c = 0
res = -1

for i in range(n-3):
    nums = seq[i:i+4]

    if countr(nums, 5) > countr(nums, 4):
        if countd(nums, 3) == countd(nums, 7):
            if sum(nums) > 2*(mx + mn):
                c += 1
                res = max(res, sum(nums))

print(c, res, n)