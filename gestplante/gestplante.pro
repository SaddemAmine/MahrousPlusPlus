QT       += core gui sql multimediawidgets

QT       += core gui multimedia

QT       += core gui printsupport

QT       +=  network

QT       += core gui widgets texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categorie_plante.cpp \
    connexion.cpp \
    gestion_categorie_plante.cpp \
    gestion_plante.cpp \
    main.cpp \
    mainwindow.cpp \
    plante.cpp \
    stat_plante.cpp

HEADERS += \
    categorie_plante.h \
    connexion.h \
    gestion_categorie_plante.h \
    gestion_plante.h \
    mainwindow.h \
    plante.h \
    stat_plante.h

FORMS += \
    categorie_plante.ui \
    mainwindow.ui \
    plante.ui \
    stat_plante.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
