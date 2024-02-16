import sys 

def divs(n, k):
    res = 0
    while n % k == 0:
        n //= k 
        res += 1 
    return res

n = int(sys.stdin.readline())
nums = []
for i in range(n):
    nums.append(int(sys.stdin.readline()))

dp = [[0 for i in range(9)] for j in range(9)]
res = 0

for x in nums:
    d2 = min(divs(x, 2), 8)
    d5 = min(divs(x, 5), 8)

    for i in range(9):
        for j in range(9):
            if min(d2 + i, d5 + j) == 7:
                res += dp[i][j]


    dp[d2][d5] += 1

print(res)