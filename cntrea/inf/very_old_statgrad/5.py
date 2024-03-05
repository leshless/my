def foo(n):
    r = bin(n)[2:]
    r1 = ""
    for i in range(len(r)):
        if r[i] == '1':
            r1 += '0'
        else:
            r1 += '1'

    return n - int(r1, 2)

for n in range(10000):
    if foo(n) == 999:
        print(n, 999)