
def is_prime(n):
  for i in range(2,n):
    if (n%i) == 0:
      return False
  return True

for s in range(40 * 3, 40 * 4 + 1):
    if is_prime(s):
       print(s)
       break