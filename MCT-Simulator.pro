TEMPLATE = app

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

SOURCES += \
    Item.cpp \
    MainWindow.cpp \
    Menu.cpp \
    Program.cpp \
    main.cpp

HEADERS += \
    Item.h \
    MainWindow.h \
    Menu.h \
    Program.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
