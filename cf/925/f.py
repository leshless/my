def solve():
    n, k = map(int, input().split())

    table = [list(map(int, input().split())) for _ in range(k)]

    if k == 1:
        print("YES")
        return

    pts = [1 for j in range(k)]
    for i in range(n-1):
        vals = set([table[j][pts[j]] for j in range(k)])
        
        if len(vals) > 2:
            print("NO")
            return
        if len(vals) == 1:
            pts = [pts[j]+1 for j in range(k)]
        
        if vals[0] != 1:
            print("NO")
            return

        for j in range(k):
            if table[j][pts[j]] == vals[1]:
                pts[j]+=1
            else if table[j][pts[j]] == vals[0]

t = int(input())


for _ in range(t):
    solve()

