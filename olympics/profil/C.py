n = int(input())
m = int(input())
data = list(map(int, input().split()))

mat = [data[i*m: (i + 1)*m] for i in range(n)]

res = 0
haunted = [False for i in range(m)]

for i in range(n):
    for j in range(m):
        a = mat[i][j]
        if a == 0:
            haunted[j] = True
        else:
            if not haunted[j]:
                res += a


print(res)
