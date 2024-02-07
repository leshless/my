def is_prime(n):
    for i in range(2, n):
        if n % i == 0:
            return 0
    return 1

for i in range(121, 200, 2):
    print(i, is_prime(i))