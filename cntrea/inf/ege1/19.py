import functools

def neighbours(s):
    if s >= 108:
        return []
    
    if s % 2 == 0:
        return (s+1, 3*s/2)
    return (s+1, 2*s)

@functools.cache
def coloring(s):
    nbs = neighbours(s)
    
    if len(nbs) == 0:
        return (False, 0)
    
    paths = [coloring(p) for p in nbs]
    trues = [p[1] for p in paths if p[0]]
    falses = [p[1] for p in paths if not p[0]]

    if len(falses) != 0:
        return (True, min(falses)+1)
    return (False, max(trues))

for s in range(1, 108):
    print(s, coloring(s))
