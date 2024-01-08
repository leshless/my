q = int(input()) 

while q % 2 == 0:
    q //= 2

res = 1
for i in range(3, q+1):
    if q % i == 0:
        d = 0
        while q % i == 0:
            q //= i 
            d += 1

        d = d*2 + 1
        res *= d
    
print(res)