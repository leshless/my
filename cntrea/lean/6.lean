inductive BinTree (T : Type) : Type
| leaf (x : T) : BinTree T
| branch (left right : BinTree T) : BinTree T


def BinTree.cata 
  (tree : BinTree T) 
  (leaf : T → R) 
  (branch : R → R → R) 
  : R :=
  match tree with
  | .leaf x => leaf x
  | .branch l r => branch (BinTree.cata l leaf branch) (BinTree.cata r leaf branch)


