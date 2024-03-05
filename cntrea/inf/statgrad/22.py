import sys 

ptime = {}
stime = {}
etime = {}
pars = {}

for l in sys.stdin.readlines():
    s = l.split()
    
    i = int(s[0])
    t = int(s[1])
    nbs = list(map(int, s[2].split(";"))) if (s[2] != "0") else []

    pars[i] = nbs
    ptime[i] = t

events = []

for i in ptime:
    if len(pars[i]) != 0:
        stime[i] = max([etime[p] for p in pars[i]])    
    else:
        stime[i] = 0

    etime[i] = stime[i] + ptime[i]

    events.append((stime[i], 1))
    events.append((etime[i], -1))

events.sort()

res = 0
for e in events:
    if e[0] > 150:
        break
    res += e[1]

print(res)