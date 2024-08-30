import sys

sys.setrecursionlimit(10000)

def h(x):
    if x < 3:
        return 1
    return 2 * x - 1 + h(x-2)

print(h(3033))