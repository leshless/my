def sumCubes (n : Nat) : Nat :=
  if n > 1
  then n ^ 3 + sumCubes (n-1)
  else 1


#eval sumCubes 4