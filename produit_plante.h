#ifndef PRODUIT_PLANTE_H
#define PRODUIT_PLANTE_H
#include "gestion_produit_plante.h"
#include <QDialog>

namespace Ui {
class produit_plante;
}

class produit_plante : public QDialog
{
    Q_OBJECT

public:
    explicit produit_plante(QWidget *parent = nullptr);
    ~produit_plante();

private slots:
    void on_pushButton_clicked();

private:
    Ui::produit_plante *ui;
    gestion_produit_plante *tmppp;
};

#endif // PRODUIT_PLANTE_H
