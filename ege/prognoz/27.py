f = open("./files/27b.txt")
n, m = map(int, f.readline().split())

N = 10000010

nums = [0 for i in range(N)]

for i in range(n):
    j, x = map(int, f.readline().split())
    x = x // 30 + (x % 30 > 0)
    nums[j] = x

s = sum(nums[:2*m+1])
res = s

i = 0
while i + 2*m + 1 < N:
    s -= nums[i]
    s += nums[i+2*m+1]
    if nums[i+m+1] != 0:
        res = max(res, s)
    i+=1
print(res)