def foo(a, b):
    res = ""
    while (a > 0):
        res += str(a % b)
        a //= b 
    
    return res[::-1]

for b in range(2, 10):
    print(b, foo(51, b))