def List.cata (nilR : R) (consR : T → R → R) (lst : List T) :=
  match lst with
  | .nil => nilR
  | .cons x xs => consR x (xs.cata nilR consR)