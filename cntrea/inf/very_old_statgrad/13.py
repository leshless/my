alph = "0123456789abcdef"
for x in alph:
    s = int(f"1{x}bad", 16) + int(f"2c{x}fe", 16)
    if s % 15 == 0:
        print(s / 15)