#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Item.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("DENAS Simulator");
    this->setFixedSize(400, 725); // Set size of the window;

    Menu* mainMenu = new Menu(this, "MAIN MENU");
    Menu* programsMenu = new Menu(this, "PROGRAMS", nullptr, mainMenu);
    Menu* frequencyMenu = new Menu(this, "FREQUENCY", nullptr, mainMenu);

    vector<Menu*>* mainMenuOptions = new vector<Menu*>;
    mainMenuOptions->push_back(programsMenu);
    mainMenuOptions->push_back(frequencyMenu);
    mainMenu->options = mainMenuOptions;

    vector<Menu*>* programOptions = new vector<Menu*>;
    programOptions->push_back(new Item(this, "ALLERGY", new Program(this, ui, 38, 600), programsMenu));
    programOptions->push_back(new Item(this, "PAIN", new Program(this, ui, 77, 900), programsMenu));
    programOptions->push_back(new Item(this, "BLOATING", new Program(this, ui, 7710, 600), programsMenu));
    programsMenu->options = programOptions;

    vector<Menu*>* frequencyOptions = new vector<Menu*>;
    frequencyOptions->push_back(new Item(this, "1.0-9.9 Hz", new Program(this, ui, 1), frequencyMenu));
    frequencyOptions->push_back(new Item(this, "10 Hz", new Program(this, ui, 10), frequencyMenu));
    frequencyOptions->push_back(new Item(this, "20 Hz", new Program(this, ui, 20), frequencyMenu));
    frequencyMenu->options = frequencyOptions;

    this->ChangeMenu(mainMenu); // start at the main menu

    // handle events
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(HandleBackButton()));
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(HandleOkButton()));
    connect(ui->leftButton, SIGNAL(clicked()), this, SLOT(HandleLeftButton()));
    connect(ui->rightButton, SIGNAL(clicked()), this, SLOT(HandleRightButton()));
    connect(ui->upButton, SIGNAL(clicked()), this, SLOT(HandleUpButton()));
    connect(ui->downButton, SIGNAL(clicked()), this, SLOT(HandleDownButton()));
    connect(ui->powerButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ChangeMenu(Menu* menu) {
    ui->menu->clear(); // Clear the current menu
    ui->menuTitle->setText(menu->GetTitle());
    this->currentMenu = menu;
    if (menu->options != nullptr) {
        for (size_t i = 0; i < menu->options->size(); i++)
            ui->menu->addItem(menu->options->at(i)->GetTitle());
        ui->menu->setCurrentRow(0); // Select the first element
    } else {
        ui->menu->addItem("Press the OK button to begin the session.");
    }
}

// Button Event Handlers
void MainWindow::HandleBackButton() {
    if (this->currentMenu->GetPreviousMenu() == nullptr) return; // Ignore since prev menu doesn't exist and can't go back further.
    if (dynamic_cast<Item *>(this->currentMenu)) dynamic_cast<Item *>(this->currentMenu)->HandleBackButton();
    this->ChangeMenu(this->currentMenu->GetPreviousMenu());
}

void MainWindow::HandleOkButton() {
    if (dynamic_cast<Item *>(this->currentMenu) != nullptr) dynamic_cast<Item *>(this->currentMenu)->HandleOkButton();
    else ChangeMenu(this->currentMenu->options->at((size_t)ui->menu->currentRow()));
}

void MainWindow::HandleLeftButton() { if (dynamic_cast<Item *>(this->currentMenu)) dynamic_cast<Item *>(this->currentMenu)->HandleLeftButton(); }
void MainWindow::HandleRightButton() { if (dynamic_cast<Item *>(this->currentMenu)) dynamic_cast<Item *>(this->currentMenu)->HandleRightButton(); }

void MainWindow::HandleUpButton() {
    if (ui->menu->currentRow()-1 < 0) return;
    ui->menu->setCurrentRow(ui->menu->currentRow()-1);
}

void MainWindow::HandleDownButton() {
    if (currentMenu->options == nullptr || (ui->menu->currentRow() + 1) >= (int)currentMenu->options->size()) return;
    ui->menu->setCurrentRow(ui->menu->currentRow()+1);
}
