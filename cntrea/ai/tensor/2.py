

m, n, p, q = A.shape

D = tensordot(eye(m, n), A, dims=2).reshape([1, 1, p, q]) + (B.reshape([B.shape[0], 1, 1, B.shape[1]]) * C.reshape([1, C.shape[0], 1, 1]))