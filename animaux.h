#ifndef ANIMAUX_H
#define ANIMAUX_H

#include <QDialog>
#include "animale.h"
#include "typeanimal.h"
#include "besoinanimal.h"
#include "produitanimal.h"
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
    besoinanimal *ba;
    produitanimal *pa;
};

#endif // ANIMAUX_H
