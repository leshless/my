import fnmatch


for n in range(0, 1000000001, 1024):
    if fnmatch.fnmatch(str(n), "3?5?21*4?"):
        print(n, n//1024)