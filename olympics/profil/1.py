from itertools import permutations

a = [x for x in range(7)]

c = 0
for p in permutations(a):
    f = True
    for i in range(7):
        f = f and p[i] != i
    if f:
        c+=1

print(c)