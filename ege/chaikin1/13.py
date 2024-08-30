def binip(ip):
    b = [bin(int(x))[2:].zfill(8) for x in ip.split(".")]
    print(" ".join(b))

ip = "172.118.1.255"
mask = "255.255.252.0"
binip(ip)
binip(mask)

import math

print(math.comb(10, 2) + math.comb(10, 4) + math.comb(10, 8) + math.comb(10, 10))