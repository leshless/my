import itertools

res = 0
for w in itertools.product("012345678", repeat=7):
    c = 0
    for x in w:
        if int(x) % 2 == 1:
            c+=1


    if (w[0] != '0') and (w.count('6') == 1) and (c == 2):
        res += 1

print(res)