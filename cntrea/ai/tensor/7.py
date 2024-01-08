# import numpy as np

def squared(xi):
    return np.array([xi[0] * xi[0], xi[1]])

def expectation(xi):
    return np.tensordot(xi[0], xi[1], axes=1)
    
def variance(xi):
    return expectation(squared(xi)) - (expectation(xi) ** 2)


# example = np.array([[1, 2, 3, 4, 5], [0.2, 0.2, 0.2, 0.2, 0.2]])
# print(expectation(example))