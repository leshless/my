# import numpy as np

# A = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])
# B = np.array([[1, 2], [3, 4]])
# C = np.array([1, 2])

D = A.reshape((A.shape[0], 1, A.shape[1], A.shape[2])) + tensordot(C, B, dims=1)
