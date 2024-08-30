n = int(input())

events = []
for i in range(n):
    t, l = map(int, input().split())
    events.append((t, l))

events.sort()
rooms = [0 for i in range(30)]

print(events) 

res1 = 0
res2 = 0

i = 0
for t in range(1440):
    if i < n:
        e = events[i]
        if e[0] == t:
            i += 1
            f = False

            for j in range(30):
                if rooms[j] <= t:
                    rooms[j] = e[0] + e[1]
                    f = True
                    break
            
            if not f:
                res1 += 1

    rc = 0
    for rt in rooms:
        if rt > t:
            rc += 1
    if rc < 15:
        res2 += 1
    
print(res1, res2)