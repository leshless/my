def f1(x, y, z, w):
    return int((x == y) and (w <= z))

def f2(x, y ,z, w):
    return int((x <= y) <= (w == z) )

print("x y z w 1 2")

for x in range(2):
    for y in range(2):
        for z in range(2):
            for w in range(2):
                print(x, y, z, w, f1(x, y, z, w), f2(x, y, z, w))