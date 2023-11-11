s = input()

ai = -1
aj = -1
bi = -1
bj = -1

res = 0
for i in range(len(s)):
    x = s[i]
    if x == "A":
        ai, aj = aj, i 
    elif x == "B":
        bi, bj = bj, i

    res = max(res, i - max(ai, bi))

print(res)