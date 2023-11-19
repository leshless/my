# import itertools
# import copy

# class Tensor:
#     def __init__(self, data):
#         shape = ()

#         tmp = data
#         while type(tmp) == list:
#             shape = shape + (len(tmp),)
#             tmp = tmp[0]

#         for index in itertools.product(*[ list(range(dim)) for dim in shape ]):
#             tmp = data
#             for i in index:
#                 tmp = tmp[i]

#         self.shape = shape
#         self.data = copy.deepcopy(data)

#     def flatten(self):
#         new_data = []

#         for index in itertools.product(*[ list(range(dim)) for dim in self.shape ]):
#             tmp = self.data
#             for i in index:
#                 tmp = tmp[i]

#             new_data.append(tmp)

#         return Tensor(new_data)

#     def reshape(self, new_shape):
#         data = self.flatten().data

#         if new_shape == ():
#             if len(data) != 1:
#                 raise RuntimeError("wrong data size for reshape")
#             return Tensor(data[0])

#         dim = new_shape[0]
#         if len(data) % dim != 0:
#                 raise RuntimeError("wrong data size for reshape")

#         width = len(data) // dim
#         parts = [ data[ width*i : width*(i+1) ] for i in range(dim) ]
#         parts = [ Tensor(part).reshape(new_shape[1:]).data for part in parts ]

#         return Tensor(parts)

#     def broadcast(self, op, other):
#         a = self
#         b = other
#         if len(a.shape) < len(b.shape):
#             diff = len(b.shape) - len(a.shape)
#             a = a.reshape( (1,)*diff + a.shape )
#         elif len(b.shape) < len(a.shape):
#             diff = len(a.shape) - len(b.shape)
#             b = b.reshape( (1,)*diff + b.shape )

#         if a.shape == ():
#             return Tensor(op(a.data, b.data))

#         dim_a = a.shape[0]
#         dim_b = b.shape[0]

#         if dim_a > 1 and dim_b > 1 and dim_a != dim_b:
#             raise RuntimeError("wrong dims for broadcast")

#         parts = []

#         for i in range(max(dim_a, dim_b)):
#             ai = min(i, dim_a-1)
#             bi = min(i, dim_b-1)
#             parts.append( Tensor(a.data[ai]).broadcast(op, Tensor(b.data[bi])).data )

#         return Tensor(parts)

#     def __add__(self, other):
#         if not isinstance(other, Tensor): other = Tensor(other)
#         return self.broadcast((lambda a, b: a+b), other)
    
#     def __radd__(self, other):
#         if not isinstance(other, Tensor): other = Tensor(other)
#         return other.broadcast((lambda a, b: a+b), self)

#     def __sub__(self, other):
#         if not isinstance(other, Tensor): other = Tensor(other)
#         return self.broadcast((lambda a, b: a-b), other)
    
#     def __rsub__(self, other):
#         if not isinstance(other, Tensor): other = Tensor(other)
#         return other.broadcast((lambda a, b: a-b), self)
    
#     def __mul__(self, other):
#         if not isinstance(other, Tensor): other = Tensor(other)
#         return self.broadcast((lambda a, b: a*b), other)
    
#     def __rmul__(self, other):
#         if not isinstance(other, Tensor): other = Tensor(other)
#         return other.broadcast((lambda a, b: a*b), self)

#     def sum(self, dim = None):
#         if dim == None:
#             return sum(self.flatten().data)

#         parts = []
#         for index in itertools.product(*[ list(range(d)) for d in self.shape[:dim] ]):
#             tmp = self.data
#             for i in index:
#                 tmp = tmp[i]

#             total = 0
#             for i in range(self.shape[dim]):
#                 total += Tensor(tmp[i])

#             parts.append( total.data )

#         return Tensor(parts).reshape( self.shape[:dim] + self.shape[dim+1:] )

#     def tensordot(self, other, dims=2):
#         # сложные dims пока не поддерживаются... (требуют нетривиального транспонирования)
#         a = self
#         b = other

#         if type(dims) != int or dims < 0 or dims > len(self.shape) or dims > len(other.shape):
#             raise RuntimeError("wrong dims for tensordot")

#         sum_index = len(a.shape) - dims
#         a = self.reshape( a.shape + (1,) * (len(b.shape) - dims) )

#         result = a * b
#         for _ in range(dims):
#             result = result.sum(dim = sum_index)

#         return result

# tensor = Tensor

# def tensordot(a, b, dims = 2): 
#     return a.tensordot(b, dims)

# def eye(a, b = None):
#     if b == None: b = a
#     return Tensor([ [ 1 if (i == j) else 0 for j in range(b) ] for i in range(a) ])


# B = Tensor([1, 2])
# C = Tensor([2, 3])
# A = Tensor([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])

i, k, l = A.shape
j = B.shape[0]
E = tensordot(B, C, dims=1)
D = A.reshape((i, 1, k, l)) + E.reshape((1, j, 1, 1))




