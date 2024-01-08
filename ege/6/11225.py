from turtle import *
tracer(0)

t = Turtle()
M = 50

t.right(60)
for i in range(2):
    t.forward(7 * M)
    t.right(120)

t.right(300)
t.forward(7 * M)

for i in range(2):
    t.right(60)
    t.forward(7 * M)
    t.right(60)

t.pu()

for x in range(-30, 30):
    for y in range(-30, 30):
        t.goto(x * M, y * M)
        t.dot()

t.hideturtle()
update()
done()