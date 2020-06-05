#ifndef BESOINANIMAUX_H
#define BESOINANIMAUX_H
#include "gestion_besoinanimaux.h"
#include"gestion_especeanimal.h"
#include "stat_besoinanimaux.h"
#include "speek/speekajouter.h"
#include <QDialog>

namespace Ui {
class besoinanimaux;
}

class besoinanimaux : public QDialog
{
    Q_OBJECT

public:
    explicit besoinanimaux(QWidget *parent = nullptr);
    ~besoinanimaux();

    void on_radioButton_6_clicked();
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

    void on_afficher_besoinanimaux_activated(const QModelIndex &index);

    void on_radioButton_4_clicked();

    void on_pushButton_4_clicked();



    int  on_pushButton_12_clicked();

private:
    Ui::besoinanimaux *ui;
    gestion_besoinanimaux tmppl;
    gestion_especeanimal tmpcat;
    stat_besoinanimaux *s;
    SpeekAjouter  sa;  

};

#endif // BESOINANIMAUX_H

