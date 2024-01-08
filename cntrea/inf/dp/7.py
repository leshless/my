n = int(input())
t = int(input())

ranges = []
for i in range(n):
    l, r = map(int, input().split())
    ranges.append((l, r))

end = [i for i in range(n)]
end.sort(key = lambda i : ranges[i][1])

pref = [0 for i in range(n)]
prev = end[0]
pref[prev] = 1

for i in range(1, n):
    cur = end[i]

    if ranges[cur][0] >= ranges[prev][1]:
        pref[cur] = pref[prev] + 1
        prev = cur 
    else:
        pref[cur] = pref[prev]



start = [i for i in range(n)]
start.sort(key = lambda i : ranges[i][0])

suf = [0 for i in range(n)]
prev = start[-1]
suf[prev] = 1

for i in range(n-1, -1, -1):
    cur = start[i]

    if ranges[cur][1] <= ranges[prev][0]:
        suf[cur] = suf[prev] + 1
        prev = cur 
    else:
        suf[cur] = suf[prev]


res = -1

i = 0
j = 0
while i < n and j < n:
    while j < n and ranges[end[i]][1] + t > ranges[start[j]][0]:
        j+=1
    
    if j == n:
        break
    
    while i < n and ranges[end[i]][1] + t <= ranges[start[j]][0]:
        res = max(res, pref[end[i]] + suf[start[j]])
        i+=1

print(res)