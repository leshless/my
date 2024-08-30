import itertools

res = []
for n in range(4):
    for a in itertools.product("0123456789", repeat=n):
        for b in range(10):
            a = "".join(a)
            num = int(f"1{a}4022{b}9")
            if num % 1987 == 0:
                res.append(num)

print(sorted(res))