# import numpy as np

def sum_value(xi, eta, distr):
    vals = xi.reshape((xi.shape[0], 1)) + eta
    return np.array([vals.flatten(), distr.flatten()])


# xi = np.array([0, 1])
# eta = np.array([2, 3])
# distr = np.array([[0.2, 0.3], [0.25, 0.25]])

# print(sum_value(xi, eta, distr))