#include "materiaux.h"
#include "ui_materiaux.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
materiaux::materiaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materiaux)
{
    ui->setupUi(this);
    QPixmap pix("A:/PROJET QT/qt/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

materiaux::~materiaux()
{
    delete ui;
}

void materiaux::on_pushButton_clicked()
{
    mm=new materielle(this );
    mm->show();
}

void materiaux::on_pushButton_2_clicked()
{
    c=new categorie(this );
    c->show();
}
