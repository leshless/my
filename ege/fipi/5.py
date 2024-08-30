def foo(n):
    r = bin(n)[2:]

    if n % 2 == 0:
        r = "10" + r
    else:
        r = "1" + r + "01"

    return int(r, 2)

for n in range(1000):
    if foo(n) > 516:
        print(n)
        break   