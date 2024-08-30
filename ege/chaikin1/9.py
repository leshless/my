import sys

res = 0
c = 1
for l in sys.stdin.readlines():
    nums = list(map(int, l.split()))

    rep = []
    for x in nums:
        if nums.count(x) > 1:
            rep.append(x)

    if len(rep):
        if (sum(rep) / len(rep) < sum(nums) / len(nums)):
            res += c
    
    c += 1

print(res)