#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <QDialog>
#include <QMediaPlayer>
#include<QDebug>
namespace Ui {
class parametre;
}

class parametre : public QDialog
{
    Q_OBJECT

public:
    explicit parametre(QWidget *parent = nullptr);
    ~parametre();
       int cl=1;
   private slots:
    void on_sliderProgresse_sliderMoved(int position);

    void on_sliderVolume_sliderMoved(int position);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_positionChanged(qint64 position );

    void on_durationChanged(qint64 position );


    //void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::parametre *ui;
    QMediaPlayer *player;
    QMediaPlayer *click;

};

#endif // PARAMETRE_H
