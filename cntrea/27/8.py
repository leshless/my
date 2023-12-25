nums = list(map(int, input().split()))
n = len(nums)
h1 = n // 2
h2 = n - h1 - 1
h3 = h1 - 1

nums = nums + nums + nums

pref = [None for i in range(3*n)]
pref[0] = nums[0]
for i in range(1, 3*n):
    pref[i] = pref[i-1] + nums[i]

suf = [None for i in range(3*n)]
suf[-1] = nums[-1]
for i in range(3*n-2, -1, -1):
    suf[i] = suf[i+1] + nums[i]


s = 0
for i in range(n-h1, n):
    s += pref[i] - pref[n-h1-1]

for i in range(n+1, n+h2+1):
    s += suf[i] - suf[n+h2+1]

rs = s
ri = 0
for i in range(n+1, 2*n):
    s += (pref[i-1] - pref[i-h1-1])
    s -= (suf[i] - suf[i+h3+1])


    if s < rs:
        rs = s
        ri = i - n

print(ri + 1)