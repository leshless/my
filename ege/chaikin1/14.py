n = 5 * 3**1917 + 6 * 2**1878 + 7 * 3**1870 - 1991


freq = {x : 0 for x in range(17)}
while n > 0:
    freq[n % 17] += 1
    n //= 17

print(freq)
