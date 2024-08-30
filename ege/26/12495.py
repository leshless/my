f = open("./files/12495.txt")

n, r, mv = map(int, f.readline().split())

nums = []
for i in range(n):
    nums.append(int(f.readline()))
nums.append(0)
nums.append(r)
nums.sort()

v = mv
res1 = 0

for i in range(n+1):
    d = nums[i+1] - nums[i]
    if v < d:
        v = mv
        res1 += 1
    v -= d

res2 = None

nums.reverse()
for x in nums:
    if r - x <= mv:
        res2 = x

print(res1, res2)