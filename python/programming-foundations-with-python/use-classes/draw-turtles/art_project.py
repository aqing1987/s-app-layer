import turtle

def draw_shapes():
    window = turtle.Screen()
    window.bgcolor("black")

    flower = turtle.Turtle()
    flower.speed(100)
    flower.shape("arrow")
    flower.right(45)

    for i in range(6, 40):
        for j in range(1, 5):
            draw_circle(flower, i, "red")
            flower.left(90)
    flower.right(45)
    flower.color("green")
    flower.forward(150)

    window.exitonclick()

def draw_circle(circle, radius, color):
    circle.color(color)
    circle.circle(radius)

draw_shapes()