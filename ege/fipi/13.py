ip = "122.159.136.144"
mask = "255.255.255.248"

print(" ".join([bin(int(x))[2:].zfill(8) for x in ip.split(".")]))
print(" ".join([bin(int(x))[2:].zfill(8) for x in mask.split(".")]))