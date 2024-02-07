f = open("2.txt")

nbs = [[] for i in range(30)]
time = [0 for i in range(30)]
et = [-1 for i in range(30)]

def count(i):
    res = 0
    for nb in nbs[i]:
        if et[nb] == -1:
            count(nb)
        res = max(res, et[nb])

    et[i] = res + time[i]

for l in f.readlines():
    id, t, dep = l.strip().split(",")
    id = int(id)
    t = int(t)

    time[id] = t
    if dep != "0":
        nbs[id] = list(map(int, dep.split("; ")))
print(nbs)

res = 0

for i in range(30):
    count(i)
    res = max(res, et[i])
print(res)