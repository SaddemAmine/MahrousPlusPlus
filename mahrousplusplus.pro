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
    connexion.cpp \
    gestion_categorie_materiel.cpp \
    historique.cpp \
    main.cpp \
    menu.cpp \
    speek/speekajouter.cpp \
    gestion_fournisseur_materiaux.cpp \
    stat_productionplante.cpp \
    stat_salaire_fonction.cpp \
    statistique_fournisseur.cpp \
    statisqtique_materiel.cpp \
    gestion_materiel.cpp \
    capture.cpp \
    image.cpp \
    gestion_affectation.cpp \
    gestion_categorie_plante.cpp \
    gestion_plante.cpp \
    photo.cpp \
    stat_plante.cpp \
    gestion_besoinanimaux.cpp \
    stat_besoinanimaux.cpp \
    gestion_productionanimaux.cpp \
    gestion_especeanimal.cpp \
    stat_productionanimaux.cpp \
    gestion_animaux.cpp \
    stat_animaux.cpp \
    gestion_besoin_plante.cpp \
    stat_besoinplantes.cpp \
    gestion_produit_plante.cpp \
    systeme.cpp \
    rh_fonctions_ops.cpp \
    rh_personnels_ops.cpp





HEADERS += \
    connexion.h \
    gestion_categorie_materiel.h \
    historique.h \
    menu.h \
    speek/speekajouter.h \
    gestion_fournisseur_materiaux.h \
    stat_productionplante.h \
    stat_salaire_fonction.h \
    statistique_fournisseur.h \
    statisqtique_materiel.h \
    capture.h \
    image.h \
    gestion_affectation.h \
    gestion_categorie_plante.h \
    gestion_plante.h \
    photo.h \
    stat_plante.h \
    gestion_besoinanimaux.h \
    stat_besoinanimaux.h \
    gestion_productionanimaux.h \
    gestion_especeanimal.h \
    stat_productionanimaux.h \
    gestion_animaux.h \
    stat_animaux.h \
    gestion_besoin_plante.h \
    stat_besoinplantes.h \
    gestion_produit_plante.h \
    gestion_materiel.h \
    systeme.h \
    rh_fonctions_ops.h \
    rh_personnels_ops.h




FORMS += \
    historique.ui \
    menu.ui \
    photo.ui \
    speek/speekajouter.ui \
    stat_productionplante.ui \
    stat_salaire_fonction.ui \
    statistique_fournisseur.ui \
    statisqtique_materiel.ui \
    capture.ui \
    image.ui \
    statisqtique_materiel.ui \
    stat_plante.ui \
    stat_besoinanimaux.ui \
    stat_productionanimaux.ui \
    stat_animaux.ui \
    stat_besoinplantes.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
TARGET = Login

RESOURCES += \
    image.qrc

QMAKE_CXXFLAGS += -std=gnu++14
RC_ICONS = icone.ico
