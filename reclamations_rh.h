#ifndef RECLAMATIONS_RH_H
#define RECLAMATIONS_RH_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "reclamations.h"

namespace Ui {
class reclamations_rh;
}

class reclamations_rh : public QDialog
{
    Q_OBJECT

public:
    explicit reclamations_rh(QWidget *parent = nullptr);
    ~reclamations_rh();

private slots:
    void on_comboBox_currentIndexChanged();

    void on_pushButton_2_clicked();

private:
    Ui::reclamations_rh *ui;
};

#endif // RECLAMATIONS_RH_H
