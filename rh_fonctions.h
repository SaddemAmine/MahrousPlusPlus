#ifndef RH_FONCTIONS_H
#define RH_FONCTIONS_H

#include "rh_fonctions_ops.h"
#include <QDialog>

namespace Ui {
class rh_fonctions;
}

class rh_fonctions : public QDialog
{
    Q_OBJECT

public:
    explicit rh_fonctions(QWidget *parent = nullptr);
    ~rh_fonctions();

private slots:
    void on_AjouterCategorieMateriel_clicked();

    void on_affichage_doubleClicked(const QModelIndex &index);

    void on_ModifierCategorieMaeriel_clicked();

    void on_SupprimerCategorieMateriel_clicked();

private:
    Ui::rh_fonctions *ui;
    bool controleDeSaisie();
};

#endif // RH_FONCTIONS_H
