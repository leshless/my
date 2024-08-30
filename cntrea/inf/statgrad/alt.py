import sys

k, *numbers = [int(x) for x in sys.stdin.read().split()]
n = len(numbers)

nums = []
for i in range(n):
    nums.append(int(input()))

pref = [0]
for i in range(1, n):
    if nums[pref[-1]] < nums[i]:
        pref.append(i)
    else:
        pref.append(pref[-1])

ind = [i for i in range(n)]
ind.sort(key = lambda i : nums[i])
ind.reverse()
ind = ind[:3]

res = -100000000000
for i in range(k, n):
    j = pref[i - k]

    for l in ind:
        if l != i and l != j:
            res = max(res, nums[i] + nums[j] + nums[l])

print(res)
