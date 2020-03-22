#ifndef ANIMALE_H
#define ANIMALE_H

#include <QDialog>

namespace Ui {
class animale;
}

class animale : public QDialog
{
    Q_OBJECT

public:
    explicit animale(QWidget *parent = nullptr);
    ~animale();

private:
    Ui::animale *ui;
};

#endif // ANIMALE_H
