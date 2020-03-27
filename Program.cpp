#include "Program.h"

Program::Program(QObject* parent, Ui::MainWindow* ui, short frequency, int duration, short powerLevel) : QObject(parent), originalDuration(duration) {
    this->ui = ui;
    this->frequency = frequency;
    this->powerLevel = powerLevel;
    this->duration = duration;
    this->sessionTime = nullptr;
}

Program::~Program() {
    delete this->sessionTime;
}

// Start the program
void Program::Start() {
    this->sessionTime = new QTimer(this);
    connect(this->sessionTime, SIGNAL(timeout()), this, SLOT(Update()));
    this->sessionTime->start(1000);
    this->duration = this->originalDuration;
}

void Program::Stop() {
    this->sessionTime->stop();
    disconnect(this->sessionTime, SIGNAL(timeout()), this, SLOT(Update()));
    delete this->sessionTime;
    this->powerLevel = 1;
}

void Program::UpdateUI() {
    ui->menu->clear();
    if (this->duration == 0) Stop();
    else if (duration > 0) {
        ui->menu->addItem("Hz: " + QString::number(this->frequency));
        ui->menu->addItem("Time Remaining: " + QString::number(this->duration) + "s");
    } else ui->menu->addItem("Time Elapsed: " + QString::number(0 - this->duration) + "s");
    ui->menu->addItem("Power Level: " + QString::number(this->powerLevel));
}

// Update method, gets called every second after the program starts
void Program::Update() {
    this->duration -= 1;
    if (this->powerLevel != 0) ui->batteryBar->setValue(ui->batteryBar->value() - (1-(1/this->powerLevel)));
    this->UpdateUI();
    if (ui->batteryBar->value() == 0) ui->powerButton->click();
}

void Program::SetPowerLevel(short powerLevel) {
    if (powerLevel < 0 || powerLevel > 100) return;
    this->powerLevel = powerLevel;
    this->UpdateUI();
}

QTimer* Program::GetTimer() { return this->sessionTime; }
short Program::GetFrequency() { return this->frequency; }
short Program::GetPowerLevel() { return this->powerLevel; }
