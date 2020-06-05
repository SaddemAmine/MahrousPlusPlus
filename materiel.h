#ifndef MATERIEL_H
#define MATERIEL_H
#include "gestion_materiel.h"
#include"gestion_categorie_materiel.h"
#include"gestion_fournisseur_materiaux.h"
#include "statisqtique_materiel.h"
#include "speek/speekajouter.h"
#include "capture.h"
#include <QDialog>

namespace Ui {
class materiel;
}

class materiel : public QDialog
{
    Q_OBJECT

public:
    explicit materiel(QWidget *parent = nullptr);
    ~materiel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_8_clicked();

   void on_radioButton_4_clicked();

    void on_radioButton_7_clicked();

    void on_pushButton_10_clicked();

    int on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void init();

    void on_afficher_materiel_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::materiel *ui;
    gestion_materiel tmpmat;
    gestion_categorie_materiel tmpcat;
    gestion_fournisseur_materiaux tmpf;
    Statisqtique_materiel *s;
    capture *c;
    SpeekAjouter  sa;
};

#endif // MATERIEL_H
