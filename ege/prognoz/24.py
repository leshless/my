f = open("./files/24.txt")

s = f.readline()
s = s.replace("C", "B")
s = s.replace("BBA", "X")

cur = 0
res = 0
for x in list(s):
    if x == "X":
        cur += 1
    else:
        cur = 0

    res = max(res, cur)

print(res*3)
