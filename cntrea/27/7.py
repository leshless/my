nums = list(map(int, input().split()))
n = len(nums)

pref = [None for i in range(n)]
pref[0] = nums[0]
for i in range(1, n):
    pref[i] = pref[i-1] + nums[i]

suf = [None for i in range(n)]
suf[-1] = nums[-1]
for i in range(n-2, -1, -1):
    suf[i] = suf[i+1] + nums[i]

s = 0
for i in range(1, n):
    s += suf[i]

rs = s
ri = 0
for i in range(1, n):
    s += pref[i-1]
    s -= suf[i]
    if s < rs:
        rs = s
        ri = i

print(ri + 1)