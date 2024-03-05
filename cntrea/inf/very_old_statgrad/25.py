from itertools import product

alph = "0123456789"
for x in product(alph, repeat=1):
    for n in range(4):
        for y in product(alph, repeat=n):
            x = "".join(x)
            y = "".join(y)
            n = int(f"1{x}493{y}41")
            if n % 2023 == 0:
                print(n)