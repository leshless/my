from itertools import product

alph = "0123456789"
for x in product(alph, repeat=1):
    x = "".join(x)
    for n in range(0, 4):
        for y in product(alph, repeat=n):
            y = "".join(y)
            n = int(f"1{x}3948{y}5")
            if (n % 3013 == 0):
                print(n)