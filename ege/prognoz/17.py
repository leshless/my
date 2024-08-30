f = open("./files/17.txt")

nums = []
for l in f.readlines():
    nums.append(int(l))

mx = max([x for x in nums if (10000 <= abs(x) <= 99999) and (abs(x) % 10 == 3)])

res = []
for i in range(len(nums)-2):
    a, b, c = nums[i], nums[i+1], nums[i+2]

    if abs(a) % 10 == 3 or abs(b) % 10 == 3 or abs(c) % 10 == 3:
        if a + b + c <= mx:
            res.append(a+b+c)

print(len(res), max(res))