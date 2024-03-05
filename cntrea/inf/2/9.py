from itertools import permutations, product

def f(row):
	x, y, z, w = row[0], row[1], row[2], row[3]
	return (x <= (y == w)) and (y == (w <= z))

def good(prows, rows):
    f1, f2, f3 = False, False, False
    
    for i in range(len(prows)):
        prow = prows[i]
        row = rows[i]

        f1 = f1 or (prow[0] and (not prow[2]) and prow[3] and f(row))
        f2 = f2 or ((not prow[0]) and (not prow[1]) and (not prow[3]) and f(row))
        f3 = f3 or ((not prow[0]) and (not prow[1]) and (not prow[2]) and prow[3] and (not f(row)))
    
    return f1 and f2 and f3

rows = []
for x, y, z, w in product((0, 1), repeat=4):
	rows.append( (x, y, z, w) )

for p in permutations("xyzw"):
    prows = []
    for row in rows:
        prows.append( [ row[ "xyzw".index(p[i]) ] for i in range(4) ])

    if good(prows, rows):
        print(p)
        break
	