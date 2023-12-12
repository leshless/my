def foo(n):
    r = 0
    a = 1 
    b = 1
    d = 0
    s = 0

    while n > 0:
        d = n % 2
        
        if d == 1:
            r += b
        
        if d + s < 2:
            n //= 2
            s = d 
        
        a, b = b, a + b 
    
    return r

s = ""
for n in range(2000, 3000):
    if (not "11" in bin(n)):
        print(bin(n), n, foo(n))