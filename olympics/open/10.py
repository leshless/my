s = 263

for d in range(2, 40):
    for x in range(d, 0, -1):
        s += 1
        if (s == 1000):
            print(d - x + 1, x)
            break