import sys 

n = int(sys.stdin.readline())
nums = []
for i in range(n):
    nums.append(int(sys.stdin.readline()))

dp = [[None for i in range(102)] for j in range(len(nums))]
for i in range(len(nums)):
    x = nums[i]
    for j in range(102):    
        if i != 0:
            dp[i][j] = dp[i-1][j]        
            
        if x % 102 == j:
            if dp[i][j] == None or dp[i][j] < x:
                dp[i][j] = x

dp1 = [[None for i in range(102)] for j in range(len(nums))]
for i in range(1, len(nums)):
    for j in range(102):
