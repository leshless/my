def foo(n):
    r = bin(n)[2:]

    if n % 2 == 0:
        r = "1" + r + "00"
    else:
        r = "10" + r + "1"

    return int(r, 2)

for n in range(1, 10000):
    if foo(n) < 1000:
        print(n, foo(n))