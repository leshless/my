import sys 

mat = []

for l in sys.stdin.readlines():
    row = list(map(int, l.split()))
    mat.append(row)

rows = [{} for i in range(len(mat))]
columns = [{} for j in range(6)]

for i in range(len(mat)):
    for j in range(6):
        val = mat[i][j]
        
        if val in rows[i]:
            rows[i][val] += 1
        else:
            rows[i][val] = 1

        if val in columns[j]:
            columns[j][val] += 1
        else:
            columns[j][val] = 1


res = 0
for i in range(len(mat)):
    count = 0
    for j in range(6):
        val = mat[i][j]

        if (rows[i][val] == 1) and (columns[j][val] > 150):
            count += 1

    if count >= 5:
        res += 1

print(res)