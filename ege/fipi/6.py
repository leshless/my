from turtle import *

tracer(0)
t = Turtle()
m = 12

for _ in range(2):
    t.forward(m*21)
    t.right(90)
    t.forward(m*27)
    t.right(90)

t.pu()
t.forward(9*m)
t.right(90)
t.forward(10*m)
t.left(90)
t.pd()

for _ in range(2):
    t.forward(m*86)
    t.right(90)
    t.forward(m*47)
    t.right(90)

t.pu()

for x in range(0, 30):
    for y in range(-30, 20):
        t.goto(x*m, y*m)
        t.dot()

done()