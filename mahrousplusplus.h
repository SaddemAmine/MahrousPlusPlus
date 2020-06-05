#ifndef MAHROUSPLUSPLUS_H
#define MAHROUSPLUSPLUS_H

#include <QDialog>
#include "gestion_fournisseur_materiaux.h"
#include "categorie_materiel.h"
#include "speek/speekajouter.h"
#include "categorie_plante.h"
#include"fournisseurs.h"
#include "especeanimal.h"
#include "plante.h"
#include "materiel.h"
#include "animaux.h"
#include "rh_fonctions.h"
#include "besoinanimaux.h"
#include"besoin_plante.h"
#include "produit_plante.h"
#include "affectation.h"
#include "rh_personnels.h"
#include "historique.h"
#include "productionanimaux.h"
#include"mahrousplusplus.h"

#include "statistique_fournisseur.h"
namespace Ui {
class mahrousplusplus;
}

class mahrousplusplus : public QDialog
{
    Q_OBJECT

public:
    explicit mahrousplusplus(QWidget *parent = nullptr);
    ~mahrousplusplus();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void init();

    void on_afficher_fournisseur_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_listView_activated(const QModelIndex &index);

    void on_pushButton_17_clicked();

   // void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    //void on_listView_2_activated(const QModelIndex &index);

    //void on_pushButton_9_clicked();

    void on_listView2_activated(const QModelIndex &index);


    void on_pushButton_18_clicked();

    void on_cx_recherche_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();
    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();



private:
    Ui::mahrousplusplus *ui;
    gestion_fournisseur_materiaux tmpf;
    //mail *m;
    Statistique_fournisseur *f;
    categorie_materiel *cm;
    categorie_plante *cp;
    especeanimal *ea;
    fournisseurs *s;
    plante *p;
    materiel *m;
    animaux *a;
    besoinanimaux *ba;
    rh_fonctions *rf;
    besoin_plante *bp;
    produit_plante *pp;
    affectation *af;
    rh_personnels *rp;
    Historique *h;
    productionanimaux *pa;
    mahrousplusplus *mpp;
QString lng;
    SpeekAjouter sa;
};

#endif // MAHROUSPLUSPLUS_H

