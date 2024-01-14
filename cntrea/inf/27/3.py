nums = list(map(int, input().split()))
n = len(nums)

pref = [nums[0]]
for i in range(1, n):
    pref.append(pref[-1] + nums[i])

res = 0
for k in range(5):
    oc = 0
    mn = (0 if k == 0 else None)
    
    for i in range(n):
        if nums[i] % 2 == 1:
            oc += 1
        
        if oc % 5 == k:
            if mn == None:
                mn = pref[i]
            else:
                mn = min(mn, pref[i])
                res = max(res, pref[i] - mn)

print(res)