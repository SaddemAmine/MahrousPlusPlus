#ifndef BESOINANIMAL_H
#define BESOINANIMAL_H

#include <QDialog>

namespace Ui {
class besoinanimal;
}

class besoinanimal : public QDialog
{
    Q_OBJECT

public:
    explicit besoinanimal(QWidget *parent = nullptr);
    ~besoinanimal();

private:
    Ui::besoinanimal *ui;
};

#endif // BESOINANIMAL_H
