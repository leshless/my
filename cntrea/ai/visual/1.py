import matplotlib.pyplot as plt
import matplotlib as mpl
import math
import sys

args = sys.argv
if len(args) < 3:
    print("Укажите желаемое имя файла и ширину изображения в аргументах коммандной строки.")
    exit(1)

name = ("image.png" if args[1] == "-" else args[1] + ".png")
width = (1280 if args[2] == "-" else int(args[2]))

LAMBDA = 50

def poisson(k):
    return math.pow(LAMBDA, k) * math.exp(-LAMBDA) / math.factorial(k)

xs = [i for i in range(100)]
ys = [poisson(k) for k in xs]


fig, ax = plt.subplots(2)
ax[0].plot(xs, ys)


plt.show()