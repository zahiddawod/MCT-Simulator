#include "Item.h"

Item::Item(QObject* parent, QString title, Program* prog, Menu* prevMenu, vector<Menu*>* options) :
    Menu(parent, title, options, prevMenu), program(prog) {}

Item::~Item() { delete program; }

void Item::HandleBackButton() {
    if (!this->program->isActive) return;
    this->program->Stop();
}
void Item::HandleOkButton() { this->program->Start(); }
void Item::HandleLeftButton() {
    if (!this->program->isActive) return;
    this->program->SetPowerLevel(this->program->GetPowerLevel() - 1);
}
void Item::HandleRightButton() {
    if (!this->program->isActive) return;
    this->program->SetPowerLevel(this->program->GetPowerLevel() + 1);
}
