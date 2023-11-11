def foo(a):
    b = bin(a)[2:]
    b += bin(a%3)[2:].zfill(2)
    b += bin(a%5)[2:].zfill(3)
    return(int(b, 2))

c = 0

for i in range(int(1_000_000_000 / 32), int(1_500_000_000 / 32)):
    x = foo(i)
    if x >= 1_111_111_110 and x <= 1_444_444_416:
        c+=1

print(c)
