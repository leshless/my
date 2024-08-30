from turtle import *

t = Turtle()
tracer(0)
m = 20

t.width(2)
for _ in range(2):
    t.forward(13*m)
    t.right(90)
    t.forward(18*m)
    t.right(90)

t.pu()
t.forward(5*m)
t.right(90)
t.forward(9*m)
t.left(90)
t.pd()

for _ in range(2):
    t.forward(11*m)
    t.right(90)
    t.forward(7*m)
    t.right(90)

t.width(0.01)
for y in range(-20, 20):
    t.pu()
    t.goto(-20*m, y*m)
    t.pd()
    t.goto(20*m, y*m)

for x in range(-20, 20):
    t.pu()
    t.goto(x*m, -20*m)
    t.pd()
    t.goto(x*m, 20*m)


done()