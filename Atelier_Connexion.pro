#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11  widgets

SOURCES += \
    animale.cpp \
    animaux.cpp \
    besoinanim.cpp \
    besoinplante.cpp \
    categorie.cpp \
    fonction.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    materiaux.cpp \
    materielle.cpp \
    personnel.cpp \
    plante.cpp \
    plantes.cpp \
    productionpalnte.cpp \
    produitanim.cpp \
    reclamations_rh.cpp \
    resh.cpp \
    typeanimal.cpp \
    typeplante.cpp


HEADERS += \
    animale.h \
    animaux.h \
    besoinanim.h \
    besoinplante.h \
    categorie.h \
    fonction.h \
        mainwindow.h \
    connection.h \
    materiaux.h \
    materielle.h \
    personnel.h \
    plante.h \
    plantes.h \
    productionpalnte.h \
    produitanim.h \
    reclamations_rh.h \
    resh.h \
    typeanimal.h \
    typeplante.h


FORMS += \
        animale.ui \
        animaux.ui \
        besoinanim.ui \
        besoinplante.ui \
        categorie.ui \
        fonction.ui \
        mainwindow.ui \
        materiaux.ui \
        materielle.ui \
        personnel.ui \
        plante.ui \
        plantes.ui \
        productionpalnte.ui \
        produitanim.ui \
        reclamations_rh.ui \
        resh.ui \
        typeanimal.ui \
        typeplante.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
