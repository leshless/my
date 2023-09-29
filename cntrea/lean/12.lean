inductive BinTree (T : Type) : Type
| leaf (x : T)
| branch (left right : BinTree T)

def BinTree.foldl (tree: BinTree T) (step : R → T → R) (init : R) : R :=
  match tree with
  | .leaf x => step init x
  | .branch l r => r.foldl step (l.foldl step init)


def myTree : BinTree Int := 
  .branch (.branch (.leaf 1) (.leaf 2)) (.branch (.leaf 3) (.leaf 4))

#eval myTree.foldl (. - .) 0