#ifndef PRODUCTIONPALNTE_H
#define PRODUCTIONPALNTE_H

#include <QDialog>

namespace Ui {
class productionpalnte;
}

class productionpalnte : public QDialog
{
    Q_OBJECT

public:
    explicit productionpalnte(QWidget *parent = nullptr);
    ~productionpalnte();

private:
    Ui::productionpalnte *ui;
};

#endif // PRODUCTIONPALNTE_H
