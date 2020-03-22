#ifndef PLANTES_H
#define PLANTES_H
#include"plante.h"
#include <QDialog>
#include "typeplante.h"
#include "besoinplante.h"
#include "productionpalnte.h"
namespace Ui {
class plantes;
}

class plantes : public QDialog
{
    Q_OBJECT

public:
    explicit plantes(QWidget *parent = nullptr);
    ~plantes();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::plantes *ui;
    plante *p;
    typeplante *tp;
    besoinplante *bp;
    productionpalnte *pp;
};

#endif // PLANTES_H
