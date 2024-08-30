N = 1000

prime = []
col = [True for i in range(N+1)]

for x in range(2, N+1):
    if col[x]:
        prime.append(x)

    for p in prime:
        if p*x > N:
            break
        col[p*x] = False

nums = []
for i in range(1, len(prime)-1):
    p1 = prime[i]
    for j in range(i+1, len(prime)):
        p2 = prime[j]

        num = (p1**2)*p2
        two = 1
        while num*two <= N:
            nums.append(num*two)
            two *= 2

        num = p1*(p2**2)
      x  two = 1
        while p1*(p2**2)*two <= N:
            nums.append(num*two)
            two *= 2

for i in range(len(prime)):
    p1 = prime[i]
    num = p1**5
    two = 1
    while num*two <= N:
        nums.append(num*two)
        two *= 2

nums.sort()
print(nums)

a, b = map(int, input().split())
for x in nums:
    if a <= x <= b:
        print(x)