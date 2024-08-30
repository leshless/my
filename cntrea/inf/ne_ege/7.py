for y in range(1000):
    x = y
    a, b = 0, 4

    while x > 0:
        if x % 11 < 8:
            a += 1
        if x % 11 > 6:
            b += x % 11
        x //= 11

    if (a, b) == (2, 14):
        print(y, a, b)