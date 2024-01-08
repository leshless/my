import functools

def neighbours(v):
    a = v[0]
    b = v[1]

    if a == 0 or b == 0:
        return []
    
    nbs = []
    for x in range(1, 4):
        if a >= x:
            nbs.append((a-x, b))
        if b >= x:
            nbs.append((a, b-x))

    if a % 2 == 0:
        nbs.append((a//2, b))
    if b % 2 == 0:
        nbs.append((a, b//2))

    return nbs 


@functools.cache
def coloring(v):
    nbs = neighbours(v)
    if len(nbs) == 0:
        return (False, 0)

    col = [coloring(u) for u in nbs]
    trues = [c[1] for c in col if c[0]]
    falses = [c[1] for c in col if not c[0]]

    if len(falses) == 0:
        return (False, max(trues))
    return (True, min(falses) + 1)


n, k = map(int, input().split())


res = 0
for a in range(1, n):
    b = n-a
    v = coloring((a, b))
    if v[0] and v[1] == k:
        res += 1

print(res)