import fnmatch

for n in range(0, 10000000001, 1917):
    if fnmatch.fnmatch(str(n), "3?12?14*5"):
        print(n, n // 1917)