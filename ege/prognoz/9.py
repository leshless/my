f = open("./files/9.txt")

res = 0
for l in f.readlines():
    nums = list(map(int, l.split()))

    once = []
    twice = []
    for x in nums:
        if nums.count(x) == 1:
            once.append(x)
        if nums.count(x) == 2:
            twice.append(x)
    
    if len(once) == 2 and len(twice) == 2:
        if once[0] % 2 == 1 and once[1] % 2 == 1 and twice[0] % 2 == 0:
            res += 1
            print(nums)

print(res)