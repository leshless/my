f = open("./files/14705.txt")

n = int(f.readline())

events = []
for i in range(n):
    s, e = map(int, f.readline().split())
    events.append((s, 1))
    events.append((e, 0))
events.sort()

cur = 0
mx = 0
for e in events:
    if e[1]:
        cur += 1
    else:
        cur -= 1

    mx = max(cur, mx)

res = 0
last = 0

for e in events:
    if e[1]:
        cur += 1
        if cur == mx:
            last = e[0]
    else:
        if cur == mx:
            res = max(res, e[0] - last)
        cur -= 1

print(mx, res)