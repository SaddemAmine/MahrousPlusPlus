#include "categorie.h"
#include "ui_categorie.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
categorie::categorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categorie)
{
    ui->setupUi(this);
    QPixmap pix("A:/PROJET QT/qt/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    click = new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("A:/PROJET QT/crud/click.mp3"));
}

categorie::~categorie()
{
    delete ui;
}

void categorie::on_pushButton_clicked()
{
    click->play();
    QString IDCATEGORIE,NOMCATEGORIE;
    IDCATEGORIE=ui->cx_idcategorie->text();
    NOMCATEGORIE=ui->cx_nomcategorie->text();

    QSqlQuery qry;
    qry.prepare("INSERT into CATEGORIESMATERIAUX (IDCATEGORIE,NOMCATEGORIE) values ('"+IDCATEGORIE+"','"+NOMCATEGORIE+"')");
    if (qry.exec())
    {

    QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void categorie::on_pushButton_2_clicked()
{
    click->play();
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from CATEGORIESMATERIAUX");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}

void categorie::on_modifier_clicked()
{
    click->play();
       QString IDCATEGORIE,NOMCATEGORIE;
       IDCATEGORIE=ui->cx_idcategorie_2->text();
       NOMCATEGORIE=ui->cx_nomcategorie_2->text();
       QSqlQuery qry;
       qry.prepare("UPDATE CATEGORIESMATERIAUX set IDCATEGORIE='"+IDCATEGORIE+"',NOMCATEGORIE='"+NOMCATEGORIE+"' where IDCATEGORIE='"+IDCATEGORIE+"'");

       if (qry.exec())
       {
       QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
       else
       {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void categorie::on_supprimer_clicked()
{
    click->play();
        QString IDCATEGORIE,NOMCATEGORIE;
        NOMCATEGORIE=ui->cx_nomcategorie_3->text();
        QSqlQuery qry;
        qry.prepare("Delete from CATEGORIESMATERIAUX where NOMCATEGORIE='"+NOMCATEGORIE+"'");

        if (qry.exec())
        {
        QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}
