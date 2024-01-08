# import numpy as np

def estimate(arr):
    n = arr.shape[0]
    s = arr.sum()

    return n / (n - s)

# def generate(alpha, N):
#     return (np.log(np.random.rand(N)) + alpha) / alpha

# print(estimate(generate(2,100500)))