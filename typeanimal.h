#ifndef TYPEANIMAL_H
#define TYPEANIMAL_H

#include <QDialog>

namespace Ui {
class typeanimal;
}

class typeanimal : public QDialog
{
    Q_OBJECT

public:
    explicit typeanimal(QWidget *parent = nullptr);
    ~typeanimal();

private:
    Ui::typeanimal *ui;
};

#endif // TYPEANIMAL_H
