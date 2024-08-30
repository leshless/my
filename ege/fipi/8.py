import itertools

c = 1
alph = "АПРСУ"
for w in itertools.product(alph, repeat=5):
    w = "".join(w)
    if (w.count("У") <= 1) and not("AA" in w):
        print(c, w)

    c += 1  