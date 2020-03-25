#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("DENAS Simulator");
    this->setFixedSize(400, 800); // Set size of the window;
}

// Deconstructor not required with the parenting system, when the Window instance is out of the stack, the objects will automatically be deleted from the heap.
MainWindow::~MainWindow() {
    delete ui;
}
