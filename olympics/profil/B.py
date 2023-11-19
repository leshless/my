s = input()

for k in range(len(s) + 1):
    l = len(s) + k

    f = 1
    for j in range(len(s)):
        f = f and ((l - j - 1 >= len(s)) or (s[j] == s[l - j - 1]))
        if f == 0:
            break
    
    if f:
        res = s
        for j in range(len(s), len(s) + k):
            res += s[l - j - 1]
        print(res)
        break
