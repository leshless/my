from itertools import combinations
from math import atan2
import sys

points = []

n = int(sys.stdin.readline().strip())
for i in range(n):
    # x, y = map(float, sys.stdin.readline().strip().split(" "))
    # points.append((round(x, 2), round(y, 2)))
    print(sys.stdin.readline().strip().split(" "))

points = sorted(points, key=lambda t: atan2(t[1], t[0]))

print(points)