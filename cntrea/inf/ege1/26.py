import sys

ranges = []

n = sys.stdin.readline()
for l in sys.stdin.readlines():
    ranges.append(list(map(int, l.split())))

ranges.sort(key = lambda r : r[0])


for 