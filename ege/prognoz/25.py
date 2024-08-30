def divsum(n):
    res = 0
    for i in range(1, n):
        if i*i > n:
            break

        if n % i == 0:
            res += i
            if i != (n // i): 
                res += (n // i)
    
    return res

import fnmatch

c = 0
for n in range(500001, 10000000):
    d = divsum(n)

    if fnmatch.fnmatch(str(d), "*7?"):
        print(n, d)
        c += 1
        if c == 5:
            break