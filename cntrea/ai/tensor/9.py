import numpy as np 

# Bi = sum j (Aij)
# Cj = sum i (Aij)

def project_distr_first(distr):
    return distr.sum(axis=1)

def project_distr_second(distr):
    return distr.sum(axis=0)

mat = np.array([[0.25, 0.25], [0.25, 0.25]])

print(project_distr_first(mat))
print(project_distr_second(mat))