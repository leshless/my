def foo(k):
    if k == 0:
        return 1
    
    if k % 2 == 1:
        return (k%10) * foo(k//100)
    
    return foo(k//100)

res = 0
for k in range(10000000, 80000000):
    if foo(k) == 35:
        res += 1    

print(res)