#ifndef BESOINANIM_H
#define BESOINANIM_H


#include <QDialog>
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
namespace Ui {
class besoinanim;
}

class besoinanim : public QDialog
{
    Q_OBJECT

public:
    explicit besoinanim(QWidget *parent = nullptr);
    ~besoinanim();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

private:
    Ui::besoinanim *ui;
    QTimer *timer;
    QMediaPlayer *click;
};

#endif // BESOINANIM_H
