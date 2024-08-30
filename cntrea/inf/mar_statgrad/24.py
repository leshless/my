s = list(input())

c = 0
d = 0
pref = []

for x in s:
    if x == "C":
        c += 1
    if x == "D":
        d += 1
    pref.append(c - d)

mn = {}
res = 0
for i in range(len(pref)):
    n = pref[i]

    if not n in mn:
        mn[n] = i
    else:
        res = max(res, i - mn[n])

print(res)