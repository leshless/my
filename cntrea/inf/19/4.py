import functools

def neighbours(v):
    a = v[0]
    b = v[1]

    if a + b > 80:
        return []
    
    nbs = []
    if a <= b:
        nbs.append((a+1, b))
        nbs.append((a+2, b))
        nbs.append((a*2, b))

    if b <= a:
        nbs.append((a, b+1))
        nbs.append((a, b+2))
        nbs.append((a, b*2))
    

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


for s in range(1, 69):
    print(s, coloring((12, s)))