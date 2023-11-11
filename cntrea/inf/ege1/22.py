import sys

ranges = []

for l in sys.stdin.readlines():
    ranges.append(list(map(int, l.split())))


c = 0
for i in range(1, 50):
    x = i / 2
    c1 = 0
    for r in ranges:
        if x > r[0] and x < r[1]:
            c1+=1
    
    if c1 == 4:
        c+=1

print(c)