def foo (m : Nat) (lst : List Nat) :=
  match lst with
  | x::y => foo (m+x) y
  | [] => m


def sumList (lst : List Nat) :=
  foo 0 lst

