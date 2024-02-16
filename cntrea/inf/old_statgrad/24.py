import sys 

def mostFrequent(s):
    freq = {}

    for x in s:
        if x in freq:
            freq[x] += 1
        else:
            freq[x] = 1

    m = 0 
    for x in freq:
        m = max(m, freq[x])

    res = ""
    for x in freq:
        if freq[x] == m:
            res += x

    return res

chars = ""
for s in sys.stdin.readlines():
    n = len(s)
    p = ""

    for i in range(1, n):
        if (s[i-1] == 'A'):
            p += s[i]

    chars += mostFrequent(p)

x = mostFrequent(chars)
print(chars.count(x))