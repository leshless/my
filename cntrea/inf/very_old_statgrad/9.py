import sys 

res = 0
for l in sys.stdin.readlines():
    nums = list(map(int, l.split()))
    
    numset = set(nums)
    freq = [nums.count(x) for x in numset]
    freq.sort()

    if freq == [1, 1, 2, 2]:
        s1 = 0
        s2 = 0
        for x in numset:
            if nums.count(x) == 1:
                s1 += x
            else:
                s2 += x
        
        if s1 > s2:
            res += 1
            print(nums)

print(res)
