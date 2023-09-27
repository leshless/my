def Array.splitAt (n : Nat) (a : Array T) : Array T × Array T :=
  Prod.mk a[:n] a[n:]

#eval #[1, 2, 3, 4].splitAt 100500