#ifndef RECLAMATIONS_P_H
#define RECLAMATIONS_P_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "reclamations.h"

namespace Ui {
class reclamations_p;
}

class reclamations_p : public QDialog
{
    Q_OBJECT

public:
    explicit reclamations_p(QWidget *parent = nullptr);
    ~reclamations_p();

private slots:
    void on_pushButton_2_clicked();
private:
    Ui::reclamations_p *ui;
};

#endif // RECLAMATIONS_P_H
