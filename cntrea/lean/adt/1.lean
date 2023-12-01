def sumCubes (n : Nat) : Nat :=
  if n > 0
  then n ^ 3 + sumCubes (n - 1)
  else 0

#eval sumCubes 100