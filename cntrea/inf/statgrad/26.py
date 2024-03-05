rows = [set([]) for i in range(100_010)]


f = open("./files/26.txt")
n = int(f.readline())
for i in range(n):
    x, y = map(int, f.readline().split())
    rows[x].add(y)

r = -1
mx = 0

for i in range(len(rows)):
    nums = sorted(list(rows[i]))
    if len(nums) == 0:
        continue
    
    prev = nums[0]        
    for j in range(1, len(nums)):
        if nums[j] - nums[j-1] - 1 > 7:
            prev = nums[j]
        else:
            cur = nums[j] - prev + 1
            if mx <= cur:
                mx = cur
                r = i

print(rows[r])
print(mx, r)