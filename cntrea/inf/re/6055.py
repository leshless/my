import re

r = re.compile(r'F([^AEF]*E([^AEF]*A[^AEF]*E){4,}[^AEF]*F)+')
r = re.compile(r'F([^EF]*E([^AEF]*A[^AEF]*E){4,}[^EF]*F)+')

s = input()

res = []
i = 0

while i < len(s):
    m = r.search(s, i)
    if m == None:
        break
    res.append((m.end() - m.start(), s[m.start():m.end()]))
    i = m.start() + 1

for entry in res:
    print(entry)
