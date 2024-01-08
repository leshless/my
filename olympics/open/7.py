def ha(a, b):
    return a != b, a and b

def foo(row):
    x1, x2, x3, x4 = row

    s1, c1 = ha(x1, x2)
    s2, c2 = ha(not x1, not x2)
    s3, c3 = ha(x3, x4)
    s4, c4 = ha(not x3, not x4)

    r1 = s1 and c2
    r2 = s2 or c3 
    r3 = s3 and c4
    r4 = s4 or c1 

    return r1 or r2 or r3 or r4 



from itertools import product

for row in product((0, 1), repeat=4):
    print(row, foo(row))