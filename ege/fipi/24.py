s = list(input())

letters = "QRW"
cur = 1
res = 1

for i in range(1, len(s)):
    if (s[i] in letters) == (s[i-1] in letters):
        cur = 1
    else:
        cur += 1

    res = max(res, cur)
print(res) 