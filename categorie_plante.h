#ifndef CATEGORIE_PLANTE_H
#define CATEGORIE_PLANTE_H
#include "gestion_categorie_plante.h"
#include <QDialog>
#include "speek/speekajouter.h"
namespace Ui {
class categorie_plante;
}

class categorie_plante : public QDialog
{
    Q_OBJECT

public:
    explicit categorie_plante(QWidget *parent = nullptr);
    ~categorie_plante();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_6_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();



void init();


    void on_afficher_categorie_activated(const QModelIndex &index);







private:
    Ui::categorie_plante *ui;
    gestion_categorie_plante tmpcat;
    SpeekAjouter  sa;
};

#endif // CATEGORIE_PLANTE_H
