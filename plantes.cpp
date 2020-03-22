#include "plantes.h"
#include "ui_plantes.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
plantes::plantes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plantes)
{
    ui->setupUi(this);
    QPixmap pix("A:/PROJET QT/qt/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

plantes::~plantes()
{
    delete ui;
}

void plantes::on_pushButton_3_clicked()
{
    p=new plante(this );
   p->show();
}

void plantes::on_pushButton_4_clicked()
{
    tp=new typeplante(this);
    tp->show();
}

void plantes::on_pushButton_5_clicked()
{
    bp=new besoinplante(this);
    bp->show();
}

void plantes::on_pushButton_6_clicked()
{
    pp=new productionpalnte (this);
    pp->show();
}
