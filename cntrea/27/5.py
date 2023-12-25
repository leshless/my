nums = list(map(int, input().split()))
n = len(nums)



table = [[None for l in range(13)] for k in range(5)]
for k in range(5):
    for l in (1, 3, 4, 12):
        for i in range(n):
            if (nums[i] % 5 == k) and (nums[i] % l == 0):
                if table[k][l] == None:
                    table[k][l] = i
                else:
                    if nums[i] > nums[table[k][l]]:
                        table[k][l] = i

res = None
for i in range(n):
    for k in range(5):
        for l in (1, 3, 4, 12):
            j = table[k][l]
            if (j != None) and (j != i):
                if (nums[i] * nums[j] % 12 == 0) and ((nums[i] + nums[j]) % 5 == 0):
                    if res == None:
                        res = nums[i] + nums[j]
                    else:
                        res = max(res, nums[i] + nums[j])


print((res if res != None else "NO"))