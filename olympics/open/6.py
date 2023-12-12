table = [
    (0, 0, 1),
    (0, 1, 0),
    (1, 1, 0),
]


def st1(row):
    x, y, z = row 
    return ((x and (not y)) == (y and z)) <= ((not y) != z)

def st2(row):
    x, y, z = row 
    return (x <= y) <= (x != z)

def st3(row):
    x, y, z = row 
    return (x <= z) == y

def st4(row):
    x, y, z = row 
    return ((not y) != z) <= (y == (not x))

def st5(row):
    x, y, z = row 
    return (not (z != x)) <= (y <= z)

for row in table:
    print(st5(row))