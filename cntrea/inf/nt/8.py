N = 1 << 32

tbl = [False] + [True for i in range(1, N)]
prime = []

for i in range(1, N):
    if tbl[i]:
        prime.append(i)
    for j in prime:
        if i*j < N:
            tbl[i*j] = False
            

a = int(input())
b = int(input())

for x in prime:
    if x >= b:
        break
    if x >= a:
        print(x, end=" ")
print()