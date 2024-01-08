def foo(n):
    r = bin(n)[2:]

    if r.count("1") % 2 == 0:
        r = r[1:]
    else:
        r = "1" * (r.count("1") + 1)
    
    if r.count("1") % 2 == 0:
        r = r[1:]
    else:
        r = "1" * (r.count("1") + 1)

    return int(r, 2)

c = 0
for n in range(1, 1001):
    if foo(n) == 7:
        c+=1

print(c)