import functools

def neighbours(p):
    nbs = []

    if p >= 103 or p % 3 == 0:
        return nbs

    if (p+1) % 3:
        nbs.append(p+1)
    if (p+2) % 3:
        nbs.append(p+2)
    nbs.append(p*2)

    return nbs 

@functools.cache
def coloring(p):
    nbs = neighbours(p)
    
    if len(nbs) == 0:
        return (False, 0)
    
    col = [coloring(v) for v in nbs]
    trues = [c[1] for c in col if c[0]]
    falses = [c[1] for c in col if not c[0]]

    if len(falses) == 0:
        return (False, max(trues))
    return (True, min(falses)+1)


for s in range(1, 102):
    c = coloring(s)
    if c == (False, 2):
        print(s, coloring(s))