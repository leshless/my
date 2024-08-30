x = 50
y = 50
dir = 0

mat = [[0 for _ in range(100)] for _ in range(100)]
mat[x][y] = 1

def forward(n):
    global x, y
    for _ in range(n):
        if dir == 0:
            y += 1
        elif dir == 1:
            x += 1
        elif dir == 2:
            y -= 1
        elif dir == 3:
            x -= 1
        
        mat[x][y] += 1

for _ in range(4):
    for _ in range(4):
        forward(7)
        dir = (dir + 1) % 4
    forward(10)
    dir = (dir + 1) % 4
    forward(4)

res = 0 
for row in mat:
    for cell in row:
        if cell == 2:
            res += 1

print(res)