a = list(map(int, input().split()))
n = len(a) // 2
a, b = a[:n], a[n:]

while b[0] != 0:
    p = a[0] // b[0]

    for i in range(n):
        a[i], b[i] = b[i], a[i] - p * b[i]


for el in a:
    print(el, end=" ")
print()

for el in b:
    print(el, end=" ")
print()