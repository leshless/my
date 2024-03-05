import itertools

alph = "0123456789"
for x in itertools.product(alph, repeat=1):
    for k in range(0, 4):
        for y in itertools.product(alph, repeat=k):
            x = "".join(x)
            y = "".join(y)

            n = int(f"1{x}7602{y}0")
            if n % 4891 == 0:
                print(n)