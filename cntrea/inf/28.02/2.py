n = int(input())

rows = {}
for i in range(n):
    i, j = map(int, input().split())

    if not i in rows:
        rows[i] = []
    rows[i].append(j)

for i in rows:
    nums = sorted(rows[i])

    mx = -1
    cur = 1
    for j in range(1, len(nums)):
        if nums[j] - nums[j-1] == 1:
            cur += 1
        else:
            cur = 1

        if cur >= 5:
            mx = nums[j]
    
    if mx != -1:
        print(i, mx)
        print(nums)
