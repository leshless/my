import sys


deps = {}
durs = {}

for l in sys.stdin.readlines():
    id, dur, dep = l.strip().split("	")
    
    id = int(id)
    dur = int(dur)
    dep = list(map(int, dep.split("; ")))
    if dep == [0]:
        dep = []
    
    deps[id] = dep 
    durs[id] = dur 

start = {}
end = {}

def dfs(u):
    if deps[u] == []:
        start[u] = 0
        end[u] = durs[u]
        return
    
    start[u] = 0
    for v in deps[u]:
        if not v in end:
            dfs(v)
        start[u] = max(start[u], end[v])
    
    end[u] = start[u] + durs[u]


events = []
for id in durs:
    dfs(id)
    events.append((start[id], True, id))
    events.append((end[id], False, id))

events.sort()

bad = False
res = 0
count = 0
last = -1

for e in events:
    time = e[0]
    if last != -1:
        if not bad:
            res = max(res, time - last)
    
    if e[1]:
        if e[2] == 2:
            bad = True
        count += 1
    else:
        if e[2] == 2:
            bad = False
        count -= 1

    if count == 5:
        last = time

print(resto)