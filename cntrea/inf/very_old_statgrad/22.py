import sys

nbs = {}
dur = {}

for l in sys.stdin.readlines():
    l = l.split()
    if len(l) == 2:
        id, d = l
        id, d = int(id), int(d)+3

        dur[id] = d
        nbs[id] = []
    else:
        id, d, deps = l
        id, d = int(id), int(d)+3
        deps = list(map(int, deps.split(";")))

        dur[id] = d
        nbs[id] = deps 

time = {}
def dfs(v):
    stime = 0    
    for u in nbs[v]:
        if not u in time:
            dfs(u)
        stime = max(stime, time[u])
    
    time[v] = stime + dur[v]

    return

res = 0
for v in nbs:
    dfs(v)
    res = max(res, time[v])

print(res-3)
