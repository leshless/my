inductive IncStringer
| mk {T : Type} (val : T) (inc : T → T) (string : T → String)

def IncStringer.inc (is : IncStringer) : IncStringer :=
  match is with
  | .mk val inc string => .mk (inc val) inc string

def IncStringer.string (is : IncStringer) : String :=
  match is with
  | .mk val _ string => string val

def IncStringer.ofInt (x : Int) : IncStringer := 
  .mk x (fun x => x + 42) (fun x => s!"{x}")
