#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include "Menu.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void ChangeMenu(Menu* menu);
private slots:
    void HandleBackButton();
    void HandleOkButton();
    void HandleLeftButton();
    void HandleRightButton();
    void HandleUpButton();
    void HandleDownButton();

private:
    Ui::MainWindow* ui;
    Menu* currentMenu;
};

#endif // WINDOW_H
