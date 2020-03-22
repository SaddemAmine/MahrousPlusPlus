#include "animaux.h"
#include "ui_animaux.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
animaux::animaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animaux)
{
    ui->setupUi(this);
    QPixmap pix("A:/PROJET QT/qt/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

animaux::~animaux()
{
    delete ui;
}

void animaux::on_pushButton_2_clicked()
{
    a = new animale(this) ;
    a->show() ;
}

void animaux::on_pushButton_3_clicked()
{
    t =new typeanimal(this);
    t->show();
}

void animaux::on_pushButton_4_clicked()
{
    ba =new besoinanimal(this);
    ba->show();
}

void animaux::on_pushButton_5_clicked()
{
    pa =new produitanimal(this);
    pa->show();
}
