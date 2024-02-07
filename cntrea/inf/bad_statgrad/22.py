f = open("./files/22.txt")

nbs = {}
time = {}
st = {}

def count(i):
    res = 0
    for nb in nbs[i]:
        if not nb in st:
            count(nb)
        res = max(res, st[nb] + time[nb]) 

    st[i] = res

for l in f.readlines():
    id, t, dep = l.strip().split()
    id = int(id)
    t = int(t)

    time[id] = t
    if dep != "0":
        nbs[id] = list(map(int, dep.split(";")))
    else:
        nbs[id] = []

for i in nbs:
    count(i)

res = 0
for i in st:
    if st[i] >= 80:
        res += 1
print(res)