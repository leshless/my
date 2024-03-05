import matplotlib.pyplot as plt
import numpy as np
import sys

LAMBDA = 15
OX_WIDTH = 31
BINOMIAL_NS = [50, 60, 80, 160]
POISSON_LAMBDAS = [6, 10, 15, 25]

def fact(arr):
    return np.array([np.math.factorial(int(x)) for x in arr])

def comb(n, k):
    return np.math.factorial(n) / fact(k) / fact(n-k)

def poisson(k, lambda_):
    return np.power(lambda_, k) * np.exp(-lambda_) / fact(k)

def binomial(k, n):
    return comb(n, k) * np.power(LAMBDA / n, k) * np.power(1 - LAMBDA/n, n-k)


args = sys.argv
if len(args) < 3:
    print("Укажите желаемое имя файла и ширину изображения в аргументах коммандной строки.\nОставьте \"-\" на местах аргументов, чтобы использовать значения по умолчанию:\nИмя файла - image.png и ширинa - 1280 пикселей.")
    exit(1)

name = ("image.png" if args[1] == "-" else args[1] + ".png")
width = (1280 if args[2] == "-" else int(args[2])) 
height = width / 4 * 3


fig, ax = plt.subplots(2)
fig.set_dpi(200)
fig.set_size_inches(width / 100, height / 100)

xs = np.linspace(0, OX_WIDTH, OX_WIDTH+1)

for i in range(len(BINOMIAL_NS)):
    n = BINOMIAL_NS[i]
    binomial_ys = binomial(xs, n)
    ax[0].plot(xs, binomial_ys, color = "r", linewidth=0.6, alpha=0.15 * (i+1), marker=".", label=f"binomial (n={n})")

poisson_ys = poisson(xs, LAMBDA)
ax[0].plot(xs, poisson_ys, color = "r", linewidth=0.6, marker=".", label=f"poisson (λ={LAMBDA})")


for i in range(len(POISSON_LAMBDAS)):
    lambda_ = POISSON_LAMBDAS[i]
    poisson_ys  = poisson(xs, lambda_)
    ax[1].plot(xs, poisson_ys, linewidth=0.6, marker=".", label=f"poisson (λ={lambda_})")


ax[0].legend()
ax[1].legend()

fig.savefig(name)