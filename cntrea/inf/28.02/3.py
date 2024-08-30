k = int(input())
n = int(input())

events = []
id = 0
for i in range(n):
    s, e = map(int, input().split())

    events.append((s, True, id))
    events.append((e, False, id))
    
    id += 1


events.sort()

ops = [True for _ in range(k)]
stored = {}
gone = {}
queue = []

res = 0
last = 0

for e in events:
    if e[1]:
        queue = [e[2]] + queue
    else:
        if e[2] in stored:
            ops[stored[e[2]]] = True
        gone[e[2]] = True

    j = 0
    for i in range(len(queue)-1, -1, -1):
        if gone[e[2]]:
            queue.pop()
            break

        while j < k and not ops[j]:
            j+=1

        if j < k:
            ops[j] = False
            stored[e[2]] = j
            queue.pop()

