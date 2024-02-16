n = int(input())

nums = []
for i in range(n):
    nums.append(int(input()))

dp = [[0 for i in range(11)] for j in range(3)]

res = 0
for x in nums:
    r = x % 3
    d = 0
    while x % 2 == 0:
        x //= 2
        d += 1
    d = min(10, d)

    for i in range(3):
        for j in range(11):
            if ((r + i) % 3 == 0) and (d + j >= 10):
                res += dp[i][j]
    
    dp[r][d] += 1

print(res)