def foo(s):
    while ("52" in s) or ("222" in s) or ("122" in s):
        if ("52" in s):
            s = s.replace("52", "11", 1)
        if ("222" in s):
            s = s.replace("222", "15", 1)
        if ("122" in s):
            s = s.replace("122", "21", 1)
    lst = list(map(int, list(s)))
    return sum(lst)

import math

res = 0
for n in range(4, 1000):
    r = foo("5" + "2" * n)
    if math.floor(math.sqrt(r)) ** 2 == r:
        print(n, r)