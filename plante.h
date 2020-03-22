#ifndef PLANTE_H
#define PLANTE_H

#include <QDialog>

namespace Ui {
class plante;
}

class plante : public QDialog
{
    Q_OBJECT

public:
    explicit plante(QWidget *parent = nullptr);
    ~plante();

private:
    Ui::plante *ui;

};

#endif // PLANTE_H
