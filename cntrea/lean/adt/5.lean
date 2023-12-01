inductive BinTree (T : Type) : Type
| leaf (x : T) : BinTree T
| branch (left right : BinTree T) : BinTree T

def BinTree.sumNats (tree : BinTree Nat) : Nat :=
match tree with
| .leaf x => x 
| .branch l r => BinTree.sumNats l + BinTree.sumNats r

