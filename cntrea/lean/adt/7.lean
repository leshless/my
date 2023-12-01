def foo (nilR : R) (consR : T → R → R) (lst : List T) (acc : R) :=
  match lst with
  | .nil => acc
  | .cons x xt => foo nilR consR xt (consR x acc)

def List.cata (nilR : R) (consR : T → R → R) (lst : List T) :=
  foo nilR consR (reverse lst) nilR

