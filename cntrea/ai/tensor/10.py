# import numpy as np

def project_distr_first(distr):
    return distr.sum(axis=1)

def project_distr_second(distr):
    return distr.sum(axis=0)

def are_independent(distr, precision=1e-6):
    xi = project_distr_first(distr)
    eta = project_distr_second(distr)
    delta = abs(distr - np.tensordot(xi, eta, axes=0))

    return (delta <= precision).all()
