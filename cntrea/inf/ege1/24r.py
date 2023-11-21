import re

s = input()
e = "/(?:^|A|B)[^AB]*A[^AB]*B[^AB]*(?:A|B|$)/g"