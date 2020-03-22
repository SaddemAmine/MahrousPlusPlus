#ifndef TYPEPLANTE_H
#define TYPEPLANTE_H

#include <QDialog>

namespace Ui {
class typeplante;
}

class typeplante : public QDialog
{
    Q_OBJECT

public:
    explicit typeplante(QWidget *parent = nullptr);
    ~typeplante();

private:
    Ui::typeplante *ui;
};

#endif // TYPEPLANTE_H
