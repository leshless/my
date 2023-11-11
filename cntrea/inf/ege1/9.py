import sys
from statistics import mean

c = 0
for l in sys.stdin.readlines():
    a = list(map(int, l.split()))

    if len(set(a)) == 6:
        a.sort()
        if mean([a[0], a[5]]) > mean(a[1:5]):
            c+=1



print(c)