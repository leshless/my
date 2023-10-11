inductive EvenOdd
| even (n : Nat)
| odd (n : Nat)

def evenOdd (e : EvenOdd) : Bool :=
  match e with 
  | .even n =>
    match n with 
    | 0 => .true
    | x+1 => evenOdd (EvenOdd.odd x)
  | .odd n =>
    match n with
    | 0 => .false
    | x+1 => evenOdd (EvenOdd.even x)
