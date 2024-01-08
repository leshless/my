for n in range(2, 20):
    m = 500
    c = 0
    while m > 0:
        m //= n
        c += 1 
    
    print(n, c)