#ifndef RESH_H
#define RESH_H

#include <QDialog>
#include "fonction.h"
#include "personnel.h"
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

private:
    Ui::resh *ui;
    fonction *f;
    personnel *p;
};

#endif // RESH_H
