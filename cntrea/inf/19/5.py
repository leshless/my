import sys
import functools

g = {}
length = {}

@functools.cache
def dfs(u):
    if not u in g:
        return length[u]
    
    res = 0
    for v in g[u]:
        res = max(res, dfs(v))
    
    return res + length[u]
    

for l in sys.stdin.readlines():
    lst = list(l.strip().split(","))
    
    u = int(lst[0])
    x = int(lst[1])
    nbs = list(map(int, lst[2].split("; ")))

    length[u] = x

    if nbs[0] != 0:
        g[u] = []
        for v in nbs:
            g[u].append(v)


res = 0
for u in g:
    res = max(res, dfs(u))

print(res)