#ifndef AFFECTATION_H
#define AFFECTATION_H
#include "gestion_affectation.h"
#include "gestion_categorie_materiel.h"
#include "gestion_materiel.h"
#include "speek/speekajouter.h"
#include <QDialog>

namespace Ui {
class affectation;
}

class affectation : public QDialog
{
    Q_OBJECT

public:
    explicit affectation(QWidget *parent = nullptr);
    ~affectation();

    void init();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_afficher_affectation_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_5_clicked();





private:
    Ui::affectation *ui;
      gestion_affectation tmpaff;
      gestion_categorie_materiel tmcat;
      gestion_materiel tmpmat;
      SpeekAjouter  sa;

};

#endif // AFFECTATION_H
