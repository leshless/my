import itertools


ok = False
c = 0
for w in itertools.product("АЕЛМНОРЬ", repeat=6):
    w = "".join(w)
    print(w)

    if ok:
        if w == "НОРМАА":
            print("OK")
            break
        else:
            c += 1
    else:
        if w == "НЕНОРМ":
            ok = True
print(c)