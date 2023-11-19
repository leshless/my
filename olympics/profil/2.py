for x in range(7):
    a = int("3144" + str(x), 7)
    if x ** 5 == a:
        print(x)