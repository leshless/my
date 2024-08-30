f = open("./files/16336b.txt")

n = int(f.readline())
nums = []
for i in range(n):
    nums.append(int(f.readline()))
nums = nums * 3

pref = [None for i in range(n*3)]
pref[0] = nums[0]
for i in range(1, 3*n):
    pref[i] = pref[i-1] + nums[i]

suf = [None for i in range(n*3)]
suf[3*n-1] = nums[3*n-1]
for i in range(3*n-2, -1, -1):
    suf[i] = suf[i+1] + nums[i]
if n % 2 == 0:
    h1 = n // 2
    h2 = h1 - 1

    s = 0
    for i in range(n-h1, n):
        s += pref[i] - pref[n-h1-1]
    for i in range(n+1, n+h2+1):
        s += suf[i] - suf[n+h2+1]

    res = s
    for i in range(n+1, 2*n):
        s += pref[i-1] - pref[i-1-h1]
        s -= suf[i] - suf[i+h1]
        res = min(res, s)

    print(res)

else:
    h = n // 2
    
    s = 0
    for i in range(n-h, n):
        s += pref[i] - pref[n-h-1]
    for i in range(n+1, n+h+1):
        s += suf[i] - suf[n+h+1]

    res = s
    for i in range(n+1, 2*n):
        s += pref[i-1] - pref[i-1-h]
        s -= suf[i] - suf[i+h]

        res = min(res, s)

    print(res)
    