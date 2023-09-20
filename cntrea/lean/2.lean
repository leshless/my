def sumCubes x :=
  match x with
  | 0   => 0
  | n+1 => x ^ 3 + sumCubes n


#eval sumCubes  1000000