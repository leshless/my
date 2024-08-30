import ipaddress

ip = bin(int(ipaddress.IPv4Address("101.157.240.0")))[2:].zfill(32)
print(ip[:16], ip[16:])

mask = bin(int(ipaddress.IPv4Address("255.255.252.0")))[2:].zfill(32)
print(mask[:16], mask[16:])

import math

res = 0
for i in range(0, 5):
    res += math.comb(10, i)
print(res)