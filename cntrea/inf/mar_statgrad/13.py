import ipaddress



ip1 = ipaddress.IPv4Address("200.60.130.4")
ip2 = ipaddress.IPv4Address("200.60.140.44")
ip3 = ipaddress.IPv4Address("200.60.150.48")


print(bin(int(ip1))[2:])
print(bin(int(ip2))[2:])
print(bin(int(ip3))[2:])