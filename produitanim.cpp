#include "produitanim.h"
#include "ui_produitanim.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
produitanim::produitanim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produitanim)
{
    ui->setupUi(this);
    QPixmap pix("D:/crud/template.png");
  int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    click = new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("D:/crud/click.mp3"));
}
produitanim::~produitanim()
{
    delete ui;
}
void produitanim::on_pushButton_2_clicked()
{
    click->play();
    QString IDPRODUCTIONANIMAUX,PRODUITPRODUCTIONANIMAUX,PRIXPRODUCTIONANIMAUX;
    IDPRODUCTIONANIMAUX=ui->cx_idcategorie->text();
    PRODUITPRODUCTIONANIMAUX=ui->cx_idcategorie_3->text();
    PRIXPRODUCTIONANIMAUX=ui->cx_nomcategorie->text();


    QSqlQuery qry;
    qry.prepare("INSERT into PRODUCTIONANIMAUX (IDPRODUCTIONANIMAUX,PRODUITPRODUCTIONANIMAUX,PRIXPRODUCTIONANIMAUX) values ('"+IDPRODUCTIONANIMAUX+"','"+PRODUITPRODUCTIONANIMAUX+"','"+PRIXPRODUCTIONANIMAUX+"')");
    if (qry.exec())
    {
    QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void produitanim::on_pushButton_3_clicked()
{
    click->play();
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from PRODUCTIONANIMAUX");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}

void produitanim::on_modifier_clicked()
{
    click->play();
    QString IDPRODUCTIONANIMAUX,IDESPECE,PRODUITPRODUCTIONANIMAUX,PRIXPRODUCTIONANIMAUX;
    IDPRODUCTIONANIMAUX=ui->cx_idcategorie->text();
    PRODUITPRODUCTIONANIMAUX=ui->cx_idcategorie_3->text();
    PRIXPRODUCTIONANIMAUX=ui->cx_nomcategorie->text();
       QSqlQuery qry;
       qry.prepare("UPDATE PRODUCTIONANIMAUX set IDPRODUCTIONANIMAUX='"+IDPRODUCTIONANIMAUX+"',IDESPECE='"+IDESPECE+"',PRODUITPRODUCTIONANIMAUX='"+PRODUITPRODUCTIONANIMAUX+"',PRIXPRODUCTIONANIMAUX='"+PRIXPRODUCTIONANIMAUX+"' where IDPRODUCTIONANIMAUX='"+IDPRODUCTIONANIMAUX+"'");

       if (qry.exec())
       {
       QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
       else
       {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void produitanim::on_supprimer_clicked()
{
    click->play();
    QString IDPRODUCTIONANIMAUX,PRODUITPRODUCTIONANIMAUX,PRIXPRODUCTIONANIMAUX;
    IDPRODUCTIONANIMAUX=ui->cx_idcategorie->text();
        QSqlQuery qry;
        qry.prepare("Delete from PRODUCTIONANIMAUX where IDPRODUCTIONANIMAUX='"+IDPRODUCTIONANIMAUX+"'");

        if (qry.exec())
        {
        QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void produitanim::on_radioButton_clicked()
{
    QSqlQueryModel  *modal = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery();
        qry->prepare("Select * from productionanimaux order by PRIXPRODUCTIONANIMAUX ");
        qry->exec();
        modal->setQuery(*qry);
        ui->table->setModel(modal);
}

void produitanim::on_pushButton_4_clicked()
{
    QSqlQueryModel  *modal = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery();
        qry->prepare("Select * from productionanimaux where IDPRODUCTIONANIMAUX like '"+ui->lineEdit->text()+"' or PRODUITPRODUCTIONANIMAUX like '"+ui->lineEdit->text()+"'" );
        qry->exec();
        modal->setQuery(*qry);
        ui->table->setModel(modal);
}

void produitanim::on_pushButton_5_clicked()
{
    s =new stats(this);
    s-> show();
}
