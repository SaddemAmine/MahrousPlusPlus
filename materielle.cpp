#include "materielle.h"
#include "ui_materielle.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
materielle::materielle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materielle)
{
    ui->setupUi(this);
    QPixmap pix("A:/PROJET QT/qt/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
      ui->status->setText("Connected...");
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
    click = new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("A:/PROJET QT/crud/click.mp3"));

}


materielle::~materielle()
{
    delete ui;
}

/*void materielle::on_pushButton_clicked()//ajout
{
click->play();
QString  IDMATERIEL,NOMMATERIEL,PRIXMATERIEL,MARQUEMATERIEL,STOCKMATERIEL;
IDMATERIEL=ui->cx_idmateriel->text();
NOMMATERIEL=ui->cx_nommatetiel->text();
PRIXMATERIEL=ui->cx_prixmateriel->text();
MARQUEMATERIEL=ui->cx_marquemateriel->text();
STOCKMATERIEL=ui->cx_stockmateriel->text();
QSqlQuery qry;
qry.prepare("INSERT into MATERIAUX (IDMATERIEL,NOMMATERIEL,PRIXMATERIEL,MARQUEMATERIEL,STOCKMATERIEL) values ('"+IDMATERIEL+"','"+NOMMATERIEL+"','"+PRIXMATERIEL+"','"+MARQUEMATERIEL+"','"+STOCKMATERIEL+"')");
if (qry.exec())
{

QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
else
{QMessageBox::critical(this,tr("Sorry"),tr("Error"));}

}
*/
