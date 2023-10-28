
a, A, b, B, n = map(int, input().split())

p1 = [a, A]
p2 = [b, B]

while(p2[0] != 0):
    d = p1[0] // p2[0]
    p1[0] -= d * p2[0]
    p1[1] -= d * p2[1]
    p1, p2 = p2, p1

if ((A - B) % n == 0):
    print(p1[1] % n)
