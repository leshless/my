from turtle import *
tracer(0)

t = Turtle()
M = 20

for i in range(2):
    t.forward(8*M)
    t.right(90)
    t.forward(18*M)
    t.right(90)

t.pu()

t.forward(4*M)
t.right(90)
t.forward(10*M)
t.left(90)

t.pd()

for i in range(2):
    t.forward(17*M)
    t.right(90)
    t.forward(7*M)
    t.right(90)

t.pu()
for x in range(-30, 30):
    for y in range(-30, 30):
        t.goto(x * M, y * M)
        t.dot()

t.hideturtle()
update()
done()