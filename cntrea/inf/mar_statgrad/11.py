import math 

for n in range(1, 1000):
    if math.ceil((42 + math.ceil(math.log2(n))) / 8) * n == 2940:
        print(n)