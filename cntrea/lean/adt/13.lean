inductive RoseTree (T : Type) : Type
| branch (val : T) (subtrees : List (RoseTree T))

mutual

def foldlist (lst : List (RoseTree T)) (step : R → T → R) (init : R) : R :=
  match lst with
  | .nil => init
  | .cons t st => foldlist st step (t.foldl step init)

def RoseTree.foldl (tree : RoseTree T) (step : R → T → R) (init : R) : R :=
  match tree with
  | .branch val st =>
    match st with
    | .nil => step init val
    | .cons x xt => foldlist xt step (x.foldl step init)

end

def myTree : RoseTree Int :=
  .branch 42 [
    .branch 1 [], 
    .branch 2 [], 
    .branch 3 [
      .branch 4 [], 
      .branch 5 []]]

#eval myTree.foldl (. - .) 0
-- (((0 - 1) - 2) - 4) - 5 = -12