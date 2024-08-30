prime = []
coloring = [True for i in range(101)]

for n in range(2, 101):
    if coloring[n]:
        prime.append(n)
    
    for p in prime:
        if p*n > 100:
            break
        coloring[p*n] = False
    
squares = []
for p in prime:
    squares.append(p*p)

res = 0
for s in squares:
    if 169 <= s <= 961:
        res += 1
print(res)