def expand (n : Fin N) : Fin (N+2) :=
  match n with
  | ⟨m, h⟩ =>
    ⟨m + 1, Nat.succ_le_succ (Nat.lt.step h)⟩
