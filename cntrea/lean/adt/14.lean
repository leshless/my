def BoehmList (T : Type _) := (R : Type _) → R → (T → R → R) → R

def List.foldR (lst : List T) (R : Type _) (init : R) (step : T → R → R) : R :=
  match lst with
  | .cons x xt => step x (xt.foldR R init step)
  | .nil => init 
  
def BoehmList.toList (lst : BoehmList T) : List T :=
  lst (List T) List.nil List.cons

def List.toBoehm (lst : List T) : BoehmList T :=
  lst.foldR

