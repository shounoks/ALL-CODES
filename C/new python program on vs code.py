import turtle
import colorsys

def draw_fractal_tree(branch_len, pen):
    if branch_len > 5:
        pen.forward(branch_len)
        pen.right(20)
        draw_fractal_tree(branch_len - 15, pen)
        pen.left(40)
        draw_fractal_tree(branch_len - 15, pen)
        pen.right(20)
        pen.backward(branch_len)

def main():
    screen = turtle.Screen()
    screen.bgcolor("black")
    screen.tracer(0)
    
    pen = turtle.Turtle()
    pen.speed(1)
    pen.width(2)
    pen.color("green")
    
    pen.penup()
    pen.goto(0, -250)
    pen.pendown()
    pen.left(90)
    draw_fractal_tree(branch_len=100, pen=pen)
    
    screen.update()
    screen.mainloop()

if __name__ == "__main__":
    main()
