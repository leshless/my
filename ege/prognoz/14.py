for x in range(8):
    n = int(f"2567{x}3", 8) + int(f"1{x}24", 8)
    if n % 7 == 0:
        print(x, n / 7)