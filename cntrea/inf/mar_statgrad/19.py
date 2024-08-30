def neighbours(p):
    if p < 13:
        return []
    
    nbs = []
    for k in range(2, p+1):
        if p % k == 0:
            nbs.append(p - p // k)
    
    return nbs

import functools

@functools.cache
def coloring(p):
    nbs = neighbours(p)
    col = [coloring(n) for n in nbs]

    trues = [c[1] for c in col if c[0]]
    falses = [c[1] for c in col if not c[0]]

    if len(falses) != 0:
        return (True, min(falses)+1)
    if len(trues) != 0:
        return (False, max(trues))
    return (False, 0)


for s in range(13, 100):
    c = coloring(s)
    if c == (False, 2):
        print(s, coloring(s))