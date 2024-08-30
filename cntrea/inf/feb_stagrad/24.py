s = list(input())

count = {"U": 0, "V": 0, "W": 0, "X": 0, "Y": 0, "Z": 0}
j = 0
res = 0

def ok():
    for x in count:
        if count[x] > 100:
            return False
    return True

for i in range(len(s)):
    x = s[i]
    if x in count:
        count[x] += 1

    while not ok(): 
        x = s[j]
        if x in count:
            count[x] -= 1
        j += 1
        
    res = max(res, i - j + 1)
