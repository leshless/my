f = open("./files/24.txt")
s = f.readline()
n = len(s)


res = 0
cur = 0
for i in range(n-2):
    chars = set((s[i], s[i+1], s[i+2]))
    if "A" in chars and "B" in chars and "C" in chars:
        cur = -2
    else:
        cur += 1
        res = max(res, cur)
print(res)
