import functools

def neighbours(p):
    if p < 10:
        return []
    
    nbs = [p-1]
    if p % 2 == 0:
        nbs.append(p//2)
    if p % 3 == 0:
        nbs.append(p*2//3)
    
    return nbs

@functools.cache
def coloring(p):
    nbs = neighbours(p)
    if len(nbs) == 0:
        return (False, 0)
    
    col = [coloring(n) for n in nbs]
    trues = [c[1] for c in col if c[0]]
    falses = [c[1] for c in col if not c[0]]

    if len(falses) == 0:
        return (False, max(trues))
    return (True, min(falses) + 1)

for s in range(10, 1000):
    if coloring(s) == (False, 2):
        print(s, coloring(s))