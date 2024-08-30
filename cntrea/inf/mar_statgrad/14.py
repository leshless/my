import itertools


res = 0
for x, y, z in itertools.product([i for i in range(80)], repeat=3):
    n = 9+8+3+x+7+5+4+z+6+2+1
    m = 8+7+z+3+5+5+y+4+9+0+1

    if (n*m % 79 == 0):
        print(x, y, z)
        res = max(res, x * 80 * 80 + y * 80 + z)

print(res)