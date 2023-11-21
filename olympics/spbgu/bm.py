def BM(string, pattern):
  
  vals = {}
  for i in range(len(pattern) - 2, -1, -1):
    if pattern[i] not in vals:
      vals[pattern[i]] = len(pattern) - i - 1
  if pattern[-1] not in vals:
    vals[pattern[-1]] = len(pattern)
  print(vals)

  i, j = len(pattern) - 1, len(pattern) - 1
  c = 0
  
  while j < len(string):
    if pattern[-1] != string[j]:
      if string[j] in vals:
        j += vals[string[j]]
      else:
        j += len(vals)
    else:
      for i in range(len(pattern) - 1, -1, -1):
        if pattern[i] != string[j - (len(pattern) - i - 1)]:
          j += vals[pattern[-1]]
          break
        else:
          if i == 0:
            c+=1
            j+=1
            break

  return c


string = "apple"
pattern = "app"
print(BM(string, pattern))             