def foo(s):
    res = ""
    nums = list(s.split("."))

    for n in nums:
        res += bin(int(n))[2:].zfill(8)
        res += "|"

    return res

a = "120.91.176.213"
b = "120.91.174.205"

print(foo(a))
print(foo(b))