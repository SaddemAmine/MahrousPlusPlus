#ifndef RESH_H
#define RESH_H

#include <QDialog>
#include "fonction.h"
#include "personnel.h"
#include "reclamations_rh.h"
namespace Ui {
class resh;
}

class resh : public QDialog
{
    Q_OBJECT

public:
    explicit resh(QWidget *parent = nullptr);
    ~resh();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::resh *ui;
    fonction *f;
    personnel *p;
    reclamations_rh * r;
};

#endif // RESH_H
