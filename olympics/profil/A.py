def step(s, f):
    s = list(s)

    br = 0

    j = 0

    matches = []
    for i in range(len(s)):
        if s[i] == '(':
            br += 1
            if br == 1:
                j = i
        if s[i] == ')':
            br -= 1
            if br == 0:
                matches.append((j, i))

    if len(matches) == 0:
        if not f:
            return s[::-1]
        return "".join(s)
    
    for m in matches:
        r = step(s[m[0] + 1: m[1]], 0)
        s[m[0] + 1: m[1]] = r 

    if f:
        while "(" in s:
            s.remove("(")
        while ")" in s:
            s.remove(")")
        return "".join(s)
    else:
        s = s[::-1]
        return s

print(step(input(), 1))