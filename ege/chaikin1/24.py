s = list(input())

cur = 0
pref = []

for x in s:
    if x == "A":
        cur += 1
    if x == "B":
        cur -= 1
    
    pref.append(cur)

first = {}
res = 0
for i in range(len(pref)):
    if pref[i] in first:
        res = max(res, i - first[pref[i]])
    else:
        first[pref[i]] = i

print(res)
