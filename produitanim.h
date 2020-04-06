#ifndef PRODUITANIM_H
#define PRODUITANIM_H

#include <QDialog>
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
namespace Ui {
class produitanim;
}

class produitanim : public QDialog
{
    Q_OBJECT

public:
    explicit produitanim(QWidget *parent = nullptr);
    ~produitanim();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_radioButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::produitanim *ui;
    QTimer *timer;
    QMediaPlayer *click;

};

#endif // PRODUITANIM_H
