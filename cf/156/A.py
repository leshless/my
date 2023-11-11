t = int(input())

for i in range(t):
    n, m = map(int, input().split())
    x = input()
    s = input()

    res = 0
    while not s in x:
        if len(x) > len(s) * 2 and res != 0:
            res = -1
            break
        x += x
        res += 1

    print(res)
