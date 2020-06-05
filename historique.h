#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QDialog>

namespace Ui {
class Historique;
}

class Historique : public QDialog
{
    Q_OBJECT

public:
    explicit Historique(QWidget *parent = nullptr);
    ~Historique();

    void ouvrirAffectation();
    void ouvrirAnimaux();
    void ouvrirBesoinPlante();
    void ouvrirPlante();
    void ouvrirMateriel();
    void ouvrirFournisseur();
    void ouvrirEspeceAnimale();
    void ouvrirCategoriePlante();
    void ouvrirCategorieMateriel();
    void ouvrirBesoinAnimaux();
    void ouvrirproductionanimal();
private slots:



    void on_pushButton_3_clicked();

    void on_pushButton_clicked();


    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_ImprimerpdfHistoriqueCategorieMateriel_clicked();

    void on_RecherhceHistoriqueCategoreMateriel_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();



    void on_pushButton_27_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();


    void on_pushButton_8_clicked();


    void on_find_clicked();

private:
    Ui::Historique *ui;
};

#endif // HISTORIQUE_H
