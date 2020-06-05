#include "parametre.h"
#include "ui_parametre.h"
#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QProgressBar>
#include <QStatusBar>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <windows.h>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
parametre::parametre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parametre)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
     cl=1;
     ui->pushButton_4->hide();
    click = new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("A:/integration/integration final/2/mahrousplusplus/click.mp3"));
    connect(player, &QMediaPlayer::positionChanged, this, &parametre::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &parametre::on_durationChanged);
    QPixmap pix("C:/Users/ASUS/Downloads/speaker.png");
    int w =ui->volume->width();
    int h =ui->volume->height();
    ui->volume->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

parametre::~parametre()
{
    delete ui;
}
void parametre::on_sliderProgresse_sliderMoved(int position)
{
player->setPosition(position);
//int pos = ui->sliderProgresse->
/*if (pos > position)
{
    QPixmap pix("C:/Users/ASUS/Downloads/next.png");
    int w =ui->progresse->width();
    int h =ui->progresse->height();
    ui->progresse->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
else if (pos<position) {
    QPixmap pix("C:/Users/ASUS/Downloads/previous.png");
    int w =ui->progresse->width();
    int h =ui->progresse->height();
    ui->progresse->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}*/
}

void parametre::on_sliderVolume_sliderMoved(int position)
{
 player->setVolume(position);
 if (position == 0)
 {
     QPixmap pix("C:/Users/ASUS/Downloads/mute (1).png");
     int w =ui->volume->width();
     int h =ui->volume->height();
     ui->volume->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
 }
 else {
     QPixmap pix("C:/Users/ASUS/Downloads/speaker.png");
     int w =ui->volume->width();
     int h =ui->volume->height();
     ui->volume->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
 }
 }


void parametre::on_pushButton_2_clicked()
{
    //Load the file
    player->setMedia(QUrl::fromLocalFile("A:\\integration\\integration final\\2\\mahrousplusplus\\Farma.mp3"));
    player->play();
    qDebug() << player->errorString();

}

void parametre::on_pushButton_clicked()
{
   player->stop();
}

void parametre::on_positionChanged(qint64 position)
{
 ui->sliderProgresse->setValue(position);
}

void parametre::on_durationChanged(qint64 position)
{
ui->sliderProgresse->setMaximum(position);
}

void parametre::on_pushButton_3_clicked()
{
    cl=0;

 ui->pushButton_4->show();
         ui->pushButton_3->hide();
        ui->pushButton_3->setStyleSheet("QPushButton{border: none;image :url(C:/Users/ASUS/Downloads/bell (1).png);}");
   ui->pushButton_3->setStyleSheet(" QPushButton:hover{border: none;image :url(C:/Users/ASUS/Downloads/bell (2).png);}");
}
