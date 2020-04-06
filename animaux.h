#ifndef ANIMAUX_H
#define ANIMAUX_H

#include <QDialog>
#include "animale.h"
#include "typeanimal.h"
#include "besoinanim.h"
#include "produitanim.h"
namespace Ui {
class animaux;
}

class animaux : public QDialog
{
    Q_OBJECT

public:
    explicit animaux(QWidget *parent = nullptr);
    ~animaux();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::animaux *ui;
    animale *a;
    typeanimal *t;
    besoinanim *ba;
    produitanim *pa;
};

#endif // ANIMAUX_H
