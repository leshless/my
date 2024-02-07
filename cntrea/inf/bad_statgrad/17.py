f = open("./files/17.txt")

nums = list(map(int, f.readlines()))
n = len(nums)

def c1(a):
    return (len(str(a)) == 3) and (str(a)[-1] == "5")

def c2(a):
    return len(str(a)) == 4

def c3(a, b, m):
    return (a*a + b*b) % m == 0

m = 100000000
for x in nums:
    if c1(x):
        m = min(x, m)

c = 0
r = 0
for i in range(n-1):
    a = nums[i]
    b = nums[i+1]

    if (c2(a) != c2(b)) and c3(a, b, m):
        c += 1
        r = max(r, a*a + b*b)

print(c, r)