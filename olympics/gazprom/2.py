import sys 
sys.setrecursionlimit(1500)

n, k = map(int, input().split())

g = [[] for x in range(n+1)]

sets = [set([])]
for i in range(1, n+1):
    u = set(list(map(int, input().split()))[1:])
    
    for j in range(len(sets)):
        v = sets[j]
        if u.issubset(v):
            g[i].append(j)
        if v.issubset(u):
            g[j].append(i)

    sets.append(u)


ban = set([])
def solve(u, acc):
    if (u == 0) and (len(ban) == n):
        return acc
    
    res = None
    for v in g[u]:
        if not v in ban:
            ban.add(v)
            
            if res == None:
                res = solve(v, acc)
            else:
                res = min(res, solve(v, acc))

            ban.remove(v)

    
    if res == None:
        return solve(0, acc+1)
    else:
        return res

print(solve(0, 0))