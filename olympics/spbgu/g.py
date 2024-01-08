# кто выиграет на цикл. отрезке длинны n <=> кто проиграет на обычн. отрезке длинны n - k

import functools

def neigbours(u): 
    if isinstance(u, int):
        u = [u] 
    else:
        u = list(u)
    n = len(u)

    nbs = []

    for i in range(len(u)):
        a = u[i]
        a -= k
        for b in range(0, a // 2 + 1):
            res = u[:i] + u[i+1:]

            if b >= k:
                res.append(b)
            if a-b >= k:
                res.append(a-b)

            nbs.append(tuple(sorted(res)))

    return nbs 


@functools.cache
def coloring(u):
    nbs = list(neigbours(u))

    if len(nbs) == 0:
        return (False, None)
    
    col = [coloring(v) for v in nbs]
    trues = [nbs[i] for i in range(len(nbs)) if col[i][0]]
    falses = [nbs[i] for i in range(len(nbs)) if not col[i][0]]

    if len(falses) == 0:
        return (False, trues)
    return (True, falses)


k = 3
for n in range(100):
    print(n, coloring(n))