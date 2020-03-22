#ifndef PRODUITANIMAL_H
#define PRODUITANIMAL_H

#include <QDialog>

namespace Ui {
class produitanimal;
}

class produitanimal : public QDialog
{
    Q_OBJECT

public:
    explicit produitanimal(QWidget *parent = nullptr);
    ~produitanimal();

private:
    Ui::produitanimal *ui;
};

#endif // PRODUITANIMAL_H
