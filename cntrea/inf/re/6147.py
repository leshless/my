import re

r = re.compile(r'(\.[^\.]*?){7,7}')
s = input()

res = []
i = 0

while i < len(s):
    m = r.search(s, i)
    if m == None:
        break
    res.append(len(m[0]))
    i = m.start() + 1

print(min(res))
