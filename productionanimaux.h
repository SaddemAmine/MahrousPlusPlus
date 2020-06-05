#ifndef PRODUCTIONANIMAUX_H
#define PRODUCTIONANIMAUX_H
#include "gestion_productionanimaux.h"
#include"gestion_especeanimal.h"
#include "stat_productionanimaux.h"
#include "speek/speekajouter.h"
#include <QDialog>

namespace Ui {
class productionanimaux;
}

class productionanimaux : public QDialog
{
    Q_OBJECT

public:
    explicit productionanimaux(QWidget *parent = nullptr);
    ~productionanimaux();

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

    void on_afficher_productionanimaux_activated(const QModelIndex &index);

    //void on_radioButton_4_clicked();

   // void on_radioButton_6_clicked();

//    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

//    void on_pushButton_7_clicked();

//    void on_pushButton_11_clicked();


    int on_pushButton_12_clicked();

private:
    Ui::productionanimaux *ui;
    gestion_productionanimaux tmppl;
    gestion_especeanimal tmpcat;
    Stat_productionanimaux *s;
    SpeekAjouter  sa;

};

#endif // PRODUCTIONANIMAUX_H

