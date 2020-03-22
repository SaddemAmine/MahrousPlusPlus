#include "resh.h"
#include "ui_resh.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
resh::resh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resh)
{
    ui->setupUi(this);
    QPixmap pix("F:/Esprit/year_2/qt/projects/crud/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

resh::~resh()
{
    delete ui;
}

void resh::on_pushButton_2_clicked()
{
    f=new fonction(this );
    f->show();
}

void resh::on_pushButton_3_clicked()
{
    p=new personnel (this);
    p->show();
}
