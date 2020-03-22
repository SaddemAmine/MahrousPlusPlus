#ifndef BESOINPLANTE_H
#define BESOINPLANTE_H

#include <QDialog>

namespace Ui {
class besoinplante;
}

class besoinplante : public QDialog
{
    Q_OBJECT

public:
    explicit besoinplante(QWidget *parent = nullptr);
    ~besoinplante();

private:
    Ui::besoinplante *ui;
};

#endif // BESOINPLANTE_H
