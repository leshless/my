for p in range(5, 15):
    for x in range(p):
        for y in range(p):
            if (p + 2) * (3*p + 4) == (x*p*p + y*p + 2):
                print(y, x, p)
                print(y*p + x)