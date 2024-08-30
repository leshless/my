import sys 


mat = []
for l in sys.stdin.readlines():
    row = list(map(int, l.split()))
    mat.append(row)

n = len(mat)
m = 6

fi = [{} for i in range(n)]
fj = [{} for j in range(m)]

for i in range(n):
    for j in range(m):
        x = mat[i][j]

        if x in fi[i]:
            fi[i][x] += 1
        else:
            fi[i][x] = 1

        if x in fj[j]:
            fj[j][x] += 1
        else:
            fj[j][x] = 1

intmat = [[0 for j in range(m)] for i in range(n)]
for i in range(n):
    for j in range(m):
        x = mat[i][j]

        if (fi[i][x] == 1) and (fj[j][x] > 150):
            intmat[i][j] = 1

res = 0
for i in range(n):
    if (sum(intmat[i]) >= 2) and (len(set(mat[i])) < 6):
        res += 1

print(res)