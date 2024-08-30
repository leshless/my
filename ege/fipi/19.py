def neighbours(p):
    a, b = p

    if a + b >= 59:
        return []
    
    return [(a+1, b), (a*2, b), (a, b+1), (a, b*2)]

import functools

@functools.cache
def coloring(p):
    col = [coloring(n) for n in neighbours(p)]
    trues = [c[1] for c in col if c[0]]
    falses = [c[1] for c in col if not c[0]]

    if len(falses) != 0:
        return (True, min(falses)+1)
    if len(trues) != 0:
        return (False, max(trues))
    return (False, 0)

for s in range(1, 54):
    p = (5, s)
    c = coloring(p)

    if c == (False, 2):
        print(s, c)