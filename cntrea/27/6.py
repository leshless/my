nums = list(map(int, input().split()))
n = len(nums)

pref = [nums[0]]
for i in range(1, n):
    pref.append(pref[-1] + nums[i])

rm = None
rl = None

for k in range(3):
    mn = (0 if k == 0 else None)
    mi = -1
    
    for i in range(n):
        if pref[i] % 3 == k:
            if mn == None or pref[i] < mn:
                mn = pref[i] 
                mi = i

            if i != mi:
                if (rm == None) or (rm < pref[i] - mn):
                    rm = pref[i] - mn
                    rl = i - mi 
                elif rm == pref[i] - mn:
                    rl = max(rl, i - mi)

if rm != None:
    print(rl, rm)
else:
    print("NO")