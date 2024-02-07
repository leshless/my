import functools

def neighbours(p):
    a = p[0]
    b = p[1]

    if b >= 48:
        return []
    else:
        nbs = [(a, b+1), (a, b+2), (a, b+3)]
        if a != b:
            nbs.append(tuple(sorted([a*2, b])))
        return nbs

@functools.cache
def coloring(p):
    nbs = neighbours(p)
    if len(nbs) == 0:
        return (False, 0)
    
    col = [coloring(nb) for nb in nbs]
    trues = [c[1] for c in col if c[0]]
    falses = [c[1] for c in col if not c[0]]

    if len(falses) == 0:
        return (False, max(trues))
    else:
        return (True, min(falses)+1)
    
for s in range(1, 48):
    c = coloring(tuple(sorted([s, 39])))
    if c == (False, 2):
        print(s, c)
