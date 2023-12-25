nums = list(map(int, input().split()))
n = len(nums)


res = 0
for k in range(15):
    pref = []
    for i in range(n):
        if (i == 0) or (pref[-1] == None):
            pref.append((nums[i] if nums[i] % 15 == k else None))
        elif (nums[i] % 15 == k):
            pref.append(max(pref[-1], nums[i]))
        else:
            pref.append(pref[-1])

    for i in range(5, n):
        if (pref[i-5] != None) and (pref[i-5] * nums[i] % 15 == 0):
            res = max(res, pref[i-5] + nums[i])



print(res)