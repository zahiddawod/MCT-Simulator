#include "Menu.h"

Menu::Menu(QObject* parent, QString title, vector<Menu*>* options, Menu* prevMenu) : QObject(parent) {
    this->title = title;
    this->options = options;
    this->prevMenu = prevMenu;
}

Menu::~Menu() {
    for(auto o : *this->options)
        delete o;
    delete this->options;
    delete prevMenu;
}

QString Menu::GetTitle() { return this->title; }
Menu* Menu::GetPreviousMenu() { return this->prevMenu; }
