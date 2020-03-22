#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QDialog>
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
namespace Ui {
class categorie;
}

class categorie : public QDialog
{
    Q_OBJECT

public:
    explicit categorie(QWidget *parent = nullptr);
    ~categorie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

private:
    Ui::categorie *ui;
    QTimer *timer;
    QMediaPlayer *click;
};

#endif // CATEGORIE_H
