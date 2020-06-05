#ifndef PHOTO_H
#define PHOTO_H

#include <QDialog>
#include<QGraphicsScene>
namespace Ui {
class photo;
}

class photo : public QDialog
{
    Q_OBJECT

public:
    explicit photo(QWidget *parent = nullptr);
    ~photo();

    void setchemin(QString n);
private:
    Ui::photo *ui;
    QGraphicsScene *scena; //l`intero mondo osservabile

    QGraphicsPixmapItem *immagine_gi;
};

#endif // PHOTO_H
