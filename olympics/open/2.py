import fractions as fr
from math import floor

a = fr.Fraction(27, 85)

m = 0
for n in range(1, 10000):
    for d in range(n+1, 10000):
        b = fr.Fraction(n, d)
        c = a + b

        s = 0
        f = True
        while c > 0:
            s+=1
            
            c -= floor(c)
            c *= 4
            
            r = floor(c)
            if r != 1:
                f = False
                break
            
            if s == 10:
                break
        
        if f:
            m = max(m, b)
            print(m)