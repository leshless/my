k = int(input())
n = int(input())

nums = []
for i in range(n):
    nums.append(int(input()))


pref1 = [nums[0]]
for i in range(1, n):
    pref1.append(max(nums[i], pref1[-1]))

mul1 = [None for i in range(k)]
for i in range(k, n):
    mul1.append(nums[i]*pref1[i-k])

pref2 = [None for i in range(k)] + [mul1[k]]
for i in range(k+1, n):
    pref2.append(max(mul1[i], pref2[-1]))

mul2 = [None for i in range(2*k)]
for i in range(2*k, n):
    mul2.append(nums[i]*pref2[i-k])

res = 0
for i in range(2*k, n):
    res = max(res, mul2[i])
print(res % 1000000007)