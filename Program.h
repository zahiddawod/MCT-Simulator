#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QTimer>

#include "ui_mainwindow.h"

class Program : public QObject {
    Q_OBJECT
public:
    explicit Program(QObject* parent = nullptr, Ui::MainWindow* ui = nullptr, short frequency = 0, int duration = 0, short powerLevel = 1);
    ~Program();
    void Start();
    void Stop();

    void SetPowerLevel(short powerLevel);
    QTimer* GetTimer();
    short GetFrequency();
    short GetPowerLevel();
    const int originalDuration;
private slots:
    void Update();
private:
    //QImage image;
    Ui::MainWindow* ui;
    short frequency, powerLevel;
    int duration;
    QTimer* sessionTime;

    void UpdateUI();
};

#endif // PROGRAM_H
