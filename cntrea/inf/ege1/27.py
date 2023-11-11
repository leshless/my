import sys

def kadan(nums, d):
    mx = nums[0]
    pref = []
    for j in range(len(nums)):
        x = nums[j]
        mx = max(mx, x)
        pref.append(mx)
    
    print(pref)

    res = nums[:]
    for j in range(d, len(nums)):
        res[j] = pref[j-d] + nums[j]

    print(res)

    mx = res[d]
    pref = res[:]
    for j in range(d, len(res)):
        x = res[j]
        mx = max(mx, x)
        pref[j] = mx
            
    print(pref)

    res1 = res[:]
    for j in range(d*2, len(res)):
        res1[j] = pref[j-d] + nums[j]

    print(res1)

    return res1


    
k = int(sys.stdin.readline())
n = int(sys.stdin.readline())

nums = []
for i in range(n):
    nums.append(int(sys.stdin.readline()))

print(max(kadan(nums, 3*k)))
