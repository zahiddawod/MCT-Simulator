#ifndef ITEM_H
#define ITEM_H

#include "Menu.h"
#include "Program.h"

class Item : public Menu {
public:
    explicit Item(QObject* parent = nullptr, QString title = "{ITEM}", Program* program = nullptr, Menu* prevMenu = nullptr, vector<Menu*>* options = nullptr);
    ~Item();
    Program* GetProgram();

    void HandleBackButton();
    void HandleOkButton();
    void HandleLeftButton();
    void HandleRightButton();
private:
    Program* program;

};

#endif // ITEM_H
