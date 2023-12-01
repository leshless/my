def Array.splitAt (n : Nat) (a : Array T) : Array T × Array T :=
  Prod.mk a[:n] a[n:]
