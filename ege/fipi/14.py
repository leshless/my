x = 2 * 729 ** 2014 + 2 * 243 ** 2016 - 2 * 81 ** 2018 + 2 * 27 ** 2020 - 2 * 9 ** 2022 - 2024

c = 0
while x > 0:
    if (x % 27) > 9:
        c += 1
    x //= 27

print(c)