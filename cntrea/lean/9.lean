partial def foo (a b res : Array Int) : Array Int :=
match a[0]? with
| .none =>
  match b[0]? with
  | .none => res
  | .some y => foo a b[1:] (.push res y)
| .some x =>
  match b[0]? with
  | .none => foo a[1:] b (.push res x)
  | .some y =>
    match compare x y with
    | .lt => foo a[1:] b (.push res x)
    | .eq => foo a[1:] b (.push res x)
    | .gt => foo a b[1:] (.push res y)


def Array.merge (a b : Array Int) : Array Int :=
foo a b .empty

