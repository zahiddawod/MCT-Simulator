#ifndef MENU_H
#define MENU_H

#include <QObject>
#include "ui_mainwindow.h"
#include <vector>

using namespace std;

class Menu : public QObject {
    Q_OBJECT
public:
    explicit Menu(QObject* parent = nullptr, QString title = "{TITLE}", vector<Menu*>* options = nullptr, Menu* prevMenu = nullptr);
    ~Menu();
    QString GetTitle();
    vector<Menu*>* options;
    Menu* GetPreviousMenu();
private:
    QString title;
    Menu* prevMenu;

};

#endif // MENU_H
