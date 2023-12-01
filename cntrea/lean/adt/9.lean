partial def foo (a b res : Array Int) (i j : Nat) : Array Int :=
match a[i]? with
| .none =>
  match b[j]? with
  | .none => res
  | .some y => foo a b (.push res y) i (j+1)
| .some x =>
  match b[j]? with
  | .none => foo a b (.push res x) (i+1) j
  | .some y =>
    match compare x y with
    | .lt => foo a b (.push res x) (i+1) j
    | .eq => foo a b (.push res x) (i+1) j
    | .gt => foo a b (.push res y) i (j+1)


def Array.merge (a b : Array Int) : Array Int :=
  foo a b .empty 0 0
