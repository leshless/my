from turtle import *
tracer(0)

t = Turtle()
M = 10

for i in range(104):
    t.forward(M)
    t.right(288)

t.pu()
for x in range(-30, 30):
    for y in range(-30, 30):
        t.goto(x * M, y * M)
        t.dot()

t.hideturtle()
update()
done()