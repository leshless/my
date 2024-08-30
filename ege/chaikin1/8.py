import itertools

nums = [0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16]

res = 0
for comb in itertools.combinations(nums, r=6):
    for perm in itertools.permutations(comb):
        if perm[0] % 2 == 0 and perm[0] != 0:
            print(perm)
            res += 1

print(res)