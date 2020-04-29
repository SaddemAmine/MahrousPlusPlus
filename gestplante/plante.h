#ifndef PLANTE_H
#define PLANTE_H
#include "gestion_plante.h"
#include"gestion_categorie_plante.h"
#include "stat_plante.h"
#include <QDialog>

namespace Ui {
class plante;
}

class plante : public QDialog
{
    Q_OBJECT

public:
    explicit plante(QWidget *parent = nullptr);
    ~plante();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_10_clicked();



    void init();

    void on_afficher_plante_activated(const QModelIndex &index);

private:
    Ui::plante *ui;
    gestion_plante tmppl;
    gestion_categorie_plante tmpcat;
    Stat_plante *s;

};

#endif // PLANTE_H

