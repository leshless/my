f = open("./files/13087.txt")

n = int(f.readline())

events = []
for i in range(n):
    s, e = map(int, f.readline().split())
    e += 20

    events.append((s, e))

events.sort(key = lambda x : x[1])

good = []
end = 0

for e in events:
    if e[0] >= end:
        good.append(e)
        end = e[1]

end = good[-2][1]
res = 0

for e in events:
    if e[0] >= end:
        res = max(res, e[0] - end + 20)

print(len(good), res)