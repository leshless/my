n = int(input())

nums = []
for i in range(n):
    nums.append(int(input()))

nums.sort()
ban = {}

gc = 0
res = 0
while len(ban) != n:
    c = 0
    prev = -5

    for i in range(n):
        if (not i in ban) and (nums[i] >= prev + 5):
            c += 1
            prev = nums[i]
            ban[i] = True
    
    gc += 1
    res = max(res, c)

print(gc, res)