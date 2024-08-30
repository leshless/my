def neighbours(p):
    if p >= 21:
        return []
    
    return [p+1, p*2]

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

for s in range(1, 21):
    c = coloring(s)
    if c == (True, 3):
        print(s, c)