f = open("./files/16336b.txt")

n = int(f.readline())
nums = []
for i in range(n):
    nums.append(int(f.readline()))

cur = sum([min(i, n-i) * nums[i] for i in range(n)])
res = cur
s = sum(nums)
l = sum(nums[1:n//2+1])

for i in range(1, n):
    cur -= l
    cur += s - l

    l -= nums[i]
    l += nums[(i+n//2) % n]

    res = min(res, cur)

print(res)