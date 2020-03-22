#ifndef MATERIAUX_H
#define MATERIAUX_H
#include "materielle.h"
#include <QDialog>
#include "categorie.h"
namespace Ui {
class materiaux;
}

class materiaux : public QDialog
{
    Q_OBJECT

public:
    explicit materiaux(QWidget *parent = nullptr);
    ~materiaux();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::materiaux *ui;
    materielle *mm;
    categorie *c;
};

#endif // MATERIAUX_H
