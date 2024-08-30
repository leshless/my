a = {3,6,9,15,16,18,28}
b = {15,16,27,28,33,42,45}
c = {3,4,6,16,28,33,42,44,51}


i = (a & b & c)

print((a&b)|(b&c) - i)
print((a-b)|(b-c) - i)
print(a-b - i)
print((a&b)|(b^c) - i)
print(b&c - i)
print(a&c - i)