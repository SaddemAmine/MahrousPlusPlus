#include "besoinanim.h"
#include "ui_besoinanim.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
besoinanim::besoinanim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::besoinanim)
{
    ui->setupUi(this);
    QPixmap pix("D:/crud/template.png");
  int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    click = new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("D:/crud/click.mp3"));
}
besoinanim::~besoinanim()
{
    delete ui;
}
void besoinanim::on_pushButton_2_clicked()
{
    click->play();
    QString IDBESOINANIMAUX,EAUANIMAUX,NUTRITIONANIMAUX,ABRIANIMAUX,VACOANIMAUX;
    IDBESOINANIMAUX=ui->cx_idcategorie->text();
    EAUANIMAUX=ui->cx_nomcategorie->text();
    NUTRITIONANIMAUX=ui->cx_nomcategorie_4->text();
    ABRIANIMAUX=ui->cx_nomcategorie_5->text();
    VACOANIMAUX=ui->cx_nomcategorie_6->text();

    QSqlQuery qry;
    qry.prepare("INSERT into BESOINSANIMAUX (IDBESOINANIMAUX,EAUANIMAUX,NUTRITIONANIMAUX,ABRIANIMAUX,VACOANIMAUX) values ('"+IDBESOINANIMAUX+"','"+EAUANIMAUX+"','"+NUTRITIONANIMAUX+"','"+ABRIANIMAUX+"','"+VACOANIMAUX+"')");
    if (qry.exec())
    {
    QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void besoinanim::on_pushButton_3_clicked()
{
    click->play();
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from BESOINSANIMAUX");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}

void besoinanim::on_modifier_clicked()
{
    click->play();
       QString IDBESOINANIMAUX,EAUANIMAUX,NUTRITIONANIMAUX,ABRIANIMAUX,VACOANIMAUX;
       IDBESOINANIMAUX=ui->cx_eau_2->text();
       EAUANIMAUX=ui->cx_eau->text();
       NUTRITIONANIMAUX=ui->cx_nutrition->text();
       ABRIANIMAUX=ui->cx_abri->text();
       VACOANIMAUX=ui->cx_vaccin->text();
       QSqlQuery qry;
       qry.prepare("UPDATE BESOINSANIMAUX set IDBESOINANIMAUX='"+IDBESOINANIMAUX+"',EAUANIMAUX='"+EAUANIMAUX+"',NUTRITIONANIMAUX='"+NUTRITIONANIMAUX+"',ABRIANIMAUX='"+ABRIANIMAUX+"',VACOANIMAUX='"+VACOANIMAUX+"' where IDBESOINANIMAUX='"+IDBESOINANIMAUX+"'");

       if (qry.exec())
       {
       QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
       else
       {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void besoinanim::on_supprimer_clicked()
{
    click->play();
        QString IDBESOINANIMAUX,EAUANIMAUX,NUTRITIONANIMAUX,ABRIANIMAUX,VACOANIMAUX;
        IDBESOINANIMAUX=ui->cx_nomcategorie_3->text();
        QSqlQuery qry;
        qry.prepare("Delete from BESOINSANIMAUX where IDBESOINANIMAUX='"+IDBESOINANIMAUX+"'");

        if (qry.exec())
        {
        QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}
