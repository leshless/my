from itertools import product

alph = "0123456789"
for n in range(4):
    for m in range(4-n):
        for a in product(alph, repeat=n):
            for b in product(alph, repeat=m):
                for c in product(alph, repeat=1):
                    a = "".join(a)
                    b = "".join(b)
                    c = "".join(c)

                    num = int(f"2{a}41{b}6{c}9")
                    if num % 9517 == 0:
                        print(num)