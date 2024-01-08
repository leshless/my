n, k = map(int, input().split())

g = [[] for x in range(n)]
pars = [0 for x in range(n)] 
ban = [False for x in range(n)]

sets = []
for i in range(n):
    u = set(list(map(int, input().split()))[1:])
    
    for j in range(len(sets)):
        v = sets[j]
        if u.issubset(v):
            g[i].append(j)
            pars[j]+=1
        if v.issubset(u):
            g[j].append(i)
            pars[i]+=1

    sets.append(u)

def dfs(u):
    ban[u] = True

    m = 999999
    mv = -1

    for v in g[u]:
        if not ban[v]:
            pars[v]-=1
            if pars[v] < m:
                m = pars[v]
                mv = v

    if m != 999999:
        dfs(mv)

def do():
    m = 999999
    mv = -1

    for v in range(n):
        if not ban[v]:
            if pars[v] < m:
                m = pars[v]
                mv = v 

    if m != 999999:
        dfs(mv)
        return True
    
    return False

res = 0
while do():
    res+=1

print(res)


