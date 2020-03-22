#include "fonction.h"
#include "ui_fonction.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
fonction::fonction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fonction)
{
    ui->setupUi(this);
    qApp->setStyle(QStyleFactory::create("Fusion"));
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

fonction::~fonction()
{
    delete ui;
}



void fonction::on_pushButton_f_clicked()//ajouter fonction
{
    click->play();
        QString IDFONCTION,NOMFONCTION,SALAIRE,DESCFONCTION;
         QSqlQuery qry;
        IDFONCTION=ui->cx_idfonction->text();
        NOMFONCTION=ui->cx_nomfonction->text();
        SALAIRE=ui->cx_salaire->text();
        DESCFONCTION=ui->cx_descfonction->text();

        qry.prepare("INSERT into FONCTIONS (IDFONCTION,NOMFONCTION,SALAIRE,DESCFONCTION) values ('"+IDFONCTION+"','"+NOMFONCTION+"','"+SALAIRE+"','"+DESCFONCTION+"')");


        if (qry.exec())
        {

        QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void fonction::on_pushButton_2_f_clicked()//afficher fonction
{
    click->play();
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from FONCTIONS");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}



void fonction::on_modifier_f_clicked()//modifier fonction   mochekla
{
    click->play();
        QString IDFONCTION,NOMFONCTION,SALAIRE,DESCFONCTION;

        IDFONCTION=ui->cx_idfonction_2->text();
        NOMFONCTION=ui->cx_nomfonction_2->text();
        SALAIRE=ui->cx_salaire_2->text();
        DESCFONCTION=ui->cx_descfonction_2->text();
        QSqlQuery qry;
        qry.prepare("UPDATE FONCTIONS set IDFONCTIONE='"+IDFONCTION+"',NOMFONCTION='"+NOMFONCTION+"',SALAIRE='"+SALAIRE+"',DESCFONCTION='"+DESCFONCTION+"' where IDFONCTION='"+IDFONCTION+"'");

        if (qry.exec())
        {
        QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}

}



void fonction::on_supprimer_f_clicked()
{
    click->play();
      QString IDFONCTION,NOMFONCTION,SALAIRE,DESCFONCTION;
        NOMFONCTION=ui->cx_nomfonction_3->text();
        QSqlQuery qry;
        qry.prepare("Delete from FONCTIONS where NOMFONCTION='"+NOMFONCTION+"'");

        if (qry.exec())
        {
        QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}
