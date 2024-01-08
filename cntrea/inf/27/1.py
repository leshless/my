import sys

def Max(a, b):
    if a == None and b == None:
        return None
    if a == None:
        return b
    if b == None:
        return a
    return max(a, b)


nums = []
for l in sys.stdin:
    lst = list(map(int, l.strip().split()))
    nums.append(lst)
n = len(nums)

table = [[None for k in range(15)] for i in range(n)]

for i in range(0, n):
    lst = nums[i]
    for x in lst:
        for k in range(15):
            if i == 0:
                s = x
            else:
                if table[i-1][k] != None:
                    s = table[i-1][k] + x
                else:
                    s = None
            if s != None:
                table[i][s % 15] = Max(table[i][s % 15], s)

res = table[n-1][0] 
print(res if res != None else "NO")
