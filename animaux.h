#ifndef ANIMAUX_H
#define ANIMAUX_H
#include "gestion_animaux.h"
#include"gestion_especeanimal.h"
#include "stat_animaux.h"
#include "speek/speekajouter.h"
#include <QDialog>

namespace Ui {
class animaux;
}

class animaux : public QDialog
{
    Q_OBJECT

public:
    explicit animaux(QWidget *parent = nullptr);
    ~animaux();

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

    void on_afficher_animaux_activated(const QModelIndex &index);

    void on_radioButton_4_clicked();

    void on_pushButton_4_clicked();



    int on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::animaux *ui;
    gestion_animaux tmppl;
    gestion_especeanimal tmpcat;
    Stat_animaux *s;
    SpeekAjouter  sa;

};

#endif // ANIMAUX_H

