def main : IO Unit := do 
  let stdin := ←IO.getStdin
  let mut total := 0

  repeat
    let line := ←stdin.getLine
    
    if line.isEmpty then break

    for word in line.split Char.isWhitespace do
      if let .some x := word.toInt? then
        total := total + x

  IO.println s!"{total}"


#print main 
#check main