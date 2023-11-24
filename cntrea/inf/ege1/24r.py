import re

s = input()
r = re.compile("[^AB]*A[^AB]*B[^AB]*|[^AB]*B[^AB]*A[^AB]*")
i = 0

res = 0

while(True):
    m = r.search(s, i)
    if not m:
        break
    
    res = max(res, len(m[0]))
    i = m.start() + 1

print(res)