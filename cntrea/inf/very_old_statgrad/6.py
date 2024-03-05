from turtle import *
import math

t = Turtle()
tracer(0)


for _ in range(11):
    t.forward(36)
    t.right(72)

pos = t.pos()
print(math.sqrt(pos[0]*pos[0] + pos[1]*pos[1]))