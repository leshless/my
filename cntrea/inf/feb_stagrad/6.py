from turtle import *
tracer(0)

t = Turtle()
t.color("rgba(0,0,0,0)")
m = 40

t.pu()
t.goto(-5*m, 5*m)
t.pd()

for i in range(4):
    for j in range(4):
        t.forward(6*m)
        t.right(90)
    
    t.forward(10*m)
    t.right(90)
    t.forward(3*m)

t.pu()
done()