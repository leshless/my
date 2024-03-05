import re

r = re.compile(r'ACF(?:AC|A)?|AFC(?:AF|A)?|CAF(?:CA|C)?|CFA(?:CF|C)?|FAC(?:FA|F)?|FCA(?:FC|F)?')
s = input()

res = [len(x) for x in r.split(s)]
print(max(res))

