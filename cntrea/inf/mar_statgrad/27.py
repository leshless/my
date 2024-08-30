k = int(input())
n = int(input())

nums = []
for i in range(n):
    nums.append(int(input()))

divs = []
for d in range(1, 100001):
    if 100000 % d == 0:
        divs.append(d)
m = len(divs)

dp = [[0 for j in range(m)] for i in range(n)]

for i in range(n):
    if i != 0:
        for j in range(m):
            dp[i][j] = dp[i-1][j]
    
    for j in range(m-1, -1, -1):
        if nums[i] % divs[j] == 0:
            dp[i][j] += 1
            break

res = 0
for i in range(2*k, n):
    for j in range(m):
        if (nums[i] * divs[j]) % 100000 == 0:
            res += dp[i-2*k][j]

print(res)