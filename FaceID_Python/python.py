from pynput import mouse


def on_click(x, y, button, pressed):
    if pressed and button == mouse.Button.left:
        print("Да, вход разрешен")
    if pressed and button == mouse.Button.right:
        print("Вы не допущены")


