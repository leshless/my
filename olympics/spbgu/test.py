
for n in range(20):
    a = []

    for i in range(1 << n):
        s = bin(i)[2:].zfill(n)

        f = True
        for p in a:
            if s in 2*p:
                f = False
                break
        if f:
            a.append(s)

    print(f'{n}:{len(a)}')