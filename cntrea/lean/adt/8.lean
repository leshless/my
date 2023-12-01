inductive SearchTree (V : Type) : Type
| empty
| branch (key : Int) (value : V) (left right : SearchTree V)
deriving Repr

def SearchTree.insert (key : Int) (x : T) (tree : SearchTree T) : SearchTree T :=
  match tree with
  | .empty => .branch key x .empty .empty
  | .branch key' v l r =>
    match compare key key' with
    | .lt => .branch key' v (l.insert key x) r
    | .eq => .branch key' x l r
    | .gt => .branch key' v l (r.insert key x)


def SearchTree.get (key : Int) (tree : SearchTree T) : Option T :=
  match tree with
  | .empty => Option.none
  | .branch key' val l r =>
    match compare key key' with
    | .lt => SearchTree.get key l
    | .eq => Option.some val
    | .gt => SearchTree.get key r