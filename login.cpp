#include "login.h"
#include "ui_login.h"
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
#include <QPixmap>
Login::Login(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::Login)
{
    ui->setupUi(this);
  QPixmap pix("C:/Users/ASUS/Downloads/logiin.png");
    int w =ui->logiin->width();
    int h =ui->logiin->height();
    ui->logiin->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    animation1 =new QPropertyAnimation (ui->pushButton,"geometry");
    animation1->setDuration(2000);
    animation1->setStartValue(ui->pushButton->geometry());
    animation1->setEndValue(QRect(720,430,91,31));

    animation2 =new QPropertyAnimation (ui->pushButton_2,"geometry");
    animation2->setDuration(2000);
    animation2->setStartValue(ui->pushButton_2->geometry());
    animation2->setEndValue(QRect(340,430,91,31));



    animationGroup =new QParallelAnimationGroup;
    animationGroup->addAnimation(animation1);
     animationGroup->addAnimation(animation2);

    animationGroup->start();


}

Login::~Login()
{
    delete ui;
}



void Login::on_pushButton_clicked()
{
    m =new Menu (this);
    m->show();
}


void Login::on_pushButton_3_clicked()
{
    p =new parametre (this);
    p->show();

}
