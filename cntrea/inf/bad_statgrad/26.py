f = open("./files/26.txt")
n = int(f.readline())

events = []
id = 0

for i in range(n):
    st, dur, t = f.readline().split()
    st, dur = int(st), int(dur)

    events.append((st, False, id, (t == "B")))
    events.append((st + dur, True, id, (t == "B")))
    id += 1

events.sort()
for e in events:
    print(e)

a = 80
b = 20
r1 = 0
r2 = 0
place = {}

for e in events:
    time, border, id, car = e
    if not border:
        if not car:
            if a != 0:
                a -= 1
                r1 += 1
                place[id] = False

            elif b != 0:
                b -= 1
                r1 += 1
                place[id] = True

            else:
                r2 += 1
        
        else:
            if b != 0:
                b -= 1
                place[id] = True

            else:
                r2 += 1
    else:
        if id in place:
            if not place[id]:
                a += 1
            else:
                b += 1

print(r1, r2)