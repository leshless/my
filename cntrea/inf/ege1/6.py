from turtle import *

tracer(False)
t = Turtle()

t.pu()
t.goto(20 * 15, 20 * 15)
t.pd()

for i in range(8):
    t.right(45)
    t.forward(8 * 15)

t.penup()

for i in range(30):
    for j in range(30):
        t.goto(i * 15, j * 15)
        t.dot()

done()