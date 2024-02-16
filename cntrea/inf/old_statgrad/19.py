import functools
import sys 



def neighbours(p):
    a = p[0]
    b = p[1]

    if a + b > 40:
        return []
    
    nbs = []
    for i in range(3):
        nbs.append(tuple(sorted([a, b+i+1])))
    if a < b:
        nbs.append(tuple(sorted([a*2, b])))

    return nbs 

@functools.cache
def coloring(p):
    nbs = neighbours(p)

    if len(nbs) == 0:
        return (False, 0)
    
    col = [coloring(n) for n in nbs]
    trues = [n[1] for n in col if n[0]]
    falses = [n[1] for n in col if not n[0]]

    if len(falses) == 0:
        return (False, max(trues))
    return (True, min(falses) + 1)



for s in range(1, 24):
    print(s, coloring(tuple(sorted([s, 17]))))