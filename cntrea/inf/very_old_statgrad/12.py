for x in range(26, 30):
    for y in range(x):
        s = y * 2 + (x - y)
        if s == 40:
            print(x, y)