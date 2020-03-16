#include "Window.h"

Window::Window(QWidget *parent) : QWidget(parent), WIDTH(400), HEIGHT(800) {
    setFixedSize(WIDTH, HEIGHT); // Set size of the window

    // Some content inside the window
    label = new QLabel("Hello Team 30!", this);
    label->setGeometry(WIDTH/2 - 50, HEIGHT/2, 100, 10);

    button = new QPushButton("CLICK ME!", this);
    button->setGeometry(WIDTH/2 - 40, HEIGHT/2 + 20, 80, 30);
}

// Deconstructor not required with the parenting system, when the Window instance is out of the stack, the objects will automatically be deleted from the heap.
Window::~Window() {
    delete label;
    delete button;
}
