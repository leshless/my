
def foo (m n : Nat) : Nat :=
  if n = 0
  then m
  else foo (m+n^3) (n-1)

def sumCubes (n : Nat) : Nat :=
  foo 0 n


#eval sumCubes 1000000