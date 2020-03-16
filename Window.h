#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Window : public QWidget {
    Q_OBJECT

public:
    explicit Window(QWidget* parent = nullptr);
    ~Window();

    const unsigned short WIDTH, HEIGHT;

private:
    QLabel* label;
    QPushButton* button;
};

#endif // WINDOW_H
