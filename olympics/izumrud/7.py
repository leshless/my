def foo(n):
    r = bin(n)[2:]

    if (r.count("1")):
        r += '1'
    else:
        r += '0'

    if (r.count("1")):
        r += '1'
    else:
        r += '0'

    return int(r, 2)

for n in range(1, 100):
    print(foo(n))
