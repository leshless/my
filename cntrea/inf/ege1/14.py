def todec(a):
    a = a[::-1]
    b = 0
    for x in a:
        b = b * 37 + int(x)
    return b 


a = "12064307"
n = todec(a)

for x in range(0, 37):
    for y in range(0, 37):
        if (n + x * 37 ** 5 + y * 37) % 36 == 0:
            print(x, y, y * 37 + x)