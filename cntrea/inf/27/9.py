import sys

pairs = []
for l in sys.stdin:
    nums = list(map(int, l.strip().split()))

    me = None 
    mo = None 
    for x in nums:
        if (x % 2 == 0):
            if me == None or x > me:
                me = x
        else:
            if mo == None or x > mo:
                mo = x
    
    pairs.append((me, mo))
n = len(pairs)
h = (n // 2) + (n % 2)

even = [p for p in pairs if p[1] == None]
odd = [p for p in pairs if p[0] == None]

all = [p for p in pairs if p[0] != None and p[1] != None]
all.sort(key = lambda p : p[1] - p[0])

pairs = even + all + odd 

res = 0
for i in range(n):
    p = pairs[i]

    if i >= h:
        if p[0] == None:
            res += p[1]
        elif p[1] == None:
            res += p[0]
        else:
            res += max(p[1], p[0])
    else:
        if p[0] == None:
            print("NO")
            exit(0)
        
        res += p[0]

print(res)