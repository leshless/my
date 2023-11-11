# import numpy as np
import numpy as np

def tensordot(A, B, dims):
    return np.tensordot(A, B, axes=dims)

eye = np.eye

A = np.array([
    [
        [[1, 2], [3, 4]],
        [[5, 6], [7, 8]],
    ],
    [
        [[9, 8], [7, 6]],
        [[5, 4], [3, 2]],
    ],
])

B = np.array([
    [1, 2], [3, 4]
])

C = np.array([9, 10])

m, n, p, q = A.shape

D = tensordot(eye(m, n), A, dims=2).reshape([1, 1, p, q]) + (B.reshape([B.shape[0], 1, 1, B.shape[1]]) * C.reshape([1, C.shape[0], 1, 1]))

print(D)