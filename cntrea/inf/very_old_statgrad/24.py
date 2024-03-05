import re

expr = re.compile(r"([CDF]{2}[AO])*")
s = input()

i = 0
res = 0

while i < len(s):
    m = expr.match(s, i)

    if m == None:
        break

    res = max(res, len(m[0]))
    i = m.end() + 1

print(res)