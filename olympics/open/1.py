x = 1e8 - 400

c = 0
for p in range(2, 1000, 3):
    if (c + (1 << p)) >= x:
        for i in range(1 << p, 1 << (p + 1)):
            c += 1
            if c == x:
                print(i)
                break
    else:
        c += 1 << p