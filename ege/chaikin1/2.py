import itertools

def foo(row):
    w, x, y, z = row
    return  ((x <= y) or (z <= w)) and (not(x <= w))

def good(rows):
    f1 = rows[0][0] and not(rows[0][1]) and rows[0][2] and not(rows[0][4])
    f2 = rows[1][0] and rows[1][3] and rows[1][4]
    f3 = rows[2][2] and not(rows[2][3]) and rows[2][4]
    return f1 and f2 and f3

def good1(rows):
    return not(rows[0][4]) and rows[1][4] and rows[2][4]


for perm in itertools.permutations([0, 1, 2, 3]):
    rows = []
    for row in itertools.product((0, 1), repeat=4):
        rows.append([row[perm[0]], row[perm[1]], row[perm[2]], row[perm[3]], int(foo(row))])
    for combrows in itertools.combinations(rows, r=3):
        for permrows in itertools.permutations(combrows):
            if good(permrows):
                word = list("wxyz")
                res = ""
                for i in perm:
                    res += word[i]
                print(res)