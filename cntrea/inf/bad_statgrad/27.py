f = open("./files/27B.txt")
n = int(f.readline())
nums = list(map(int, f.readlines()))

dp = [[0 for _ in range(9)] for _ in range(9)]
res = 0
for i in range(n):
    x = nums[i]
    r, p = x % 9, i % 9

    for r1 in range(9):
        for p1 in range(9):
            if (r + r1) % 9 == (p - p1) % 9:
                res += dp[r1][p1]
    
    dp[r][p] += 1

print(res)