import sys

c = 0
for l in sys.stdin.readlines():
    nums = list(map(int, l.split()))
    nums.sort()

    if sum(nums[:3]) > nums[3]:
        if (nums[0] + nums[3] == nums[1] + nums[2]) or (nums[0] + nums[2] == nums[1] + nums[3]):
            c += 1
            print(nums)

print(c)