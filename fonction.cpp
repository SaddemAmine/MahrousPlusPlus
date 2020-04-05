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

        //combo box modif categorie
         QSqlQueryModel * model2 = new QSqlQueryModel();
         QSqlQuery * query2 = new QSqlQuery();
         query2->prepare("select idfonction||' '||nomfonction ,idfonction,nomfonction from FONCTIONS;");
         query2->exec();
         model2->setQuery(*query2);
         ui->comboBox_modif->setModel(model2);
         ui->comboBox_sup->setModel(model2);

}

fonction::~fonction()
{
    delete ui;
}




void fonction::on_pushButton_f_clicked()
{
    QString IDFONCTION,NOMFONCTION,SALAIRE,DESCFONCTION;
    IDFONCTION=ui->cx_idfonction->text();
    NOMFONCTION=ui->cx_nomfonction->text();
    SALAIRE=ui->cx_salaire->text();
    DESCFONCTION=ui->cx_descfonction->text();
    //QAbstractItemModel * m = ui->comboBox->model();
   // IDFONCTION = m->data(m->index(ui->comboBox->currentIndex(),1)).toString();
    QSqlQuery qry;
    qDebug() << qry.prepare("INSERT into FONCTIONS values (:idfonction , :nomfonction , :salaire , :descfonction )");
    qry.bindValue(":idfonction",IDFONCTION);
    qry.bindValue(":nomfonction",NOMFONCTION);
    qry.bindValue(":salaire",SALAIRE);
    qry.bindValue(":descfonction",DESCFONCTION);


    if (qry.exec())
    {

    QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void fonction::on_pushButton_2_f_clicked()
{
    click->play();
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from FONCTIONS");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}

void fonction::on_comboBox_modif_currentIndexChanged()
{
    QAbstractItemModel * m = ui->comboBox_modif->model();
    QString whereClause = m->data(m->index(ui->comboBox_modif->currentIndex(),1)).toString();

    QSqlQuery * modquery1 = new QSqlQuery();


    modquery1->prepare("select * from FONCTIONS where idfonction = '"+whereClause+"';");
    modquery1->exec();

    while(modquery1->next()){
        ui->cx_idfonction_2->setText(modquery1->value("idfonction").toString());
        ui->cx_nomfonction_2->setText(modquery1->value("nomfonction").toString());
         ui->cx_salaire_2->setText(modquery1->value("salaire").toString());

        ui->cx_descfonction_2->setText(modquery1->value("DESCFONCTION").toString());
    }

}

void fonction::on_modifier_f_clicked()
{
    QAbstractItemModel * m = ui->comboBox_modif->model();
        QString AIDFONCTION,IDFONCTION,NOMFONCTION,SALAIRE,DESCFONCTION;

        AIDFONCTION = m->data(m->index(ui->comboBox_modif->currentIndex(),1)).toString();//ancien CIN
        IDFONCTION=ui->cx_idfonction_2->text();
        NOMFONCTION=ui->cx_nomfonction_2->text();
        SALAIRE=ui->cx_salaire_2->text();
        DESCFONCTION=ui->cx_descfonction_2->text();


        QSqlQuery qry;
        qDebug() << qry.prepare("update FONCTIONS set idfonction = :idfonction , nomfonction = :nomfonction , salaire = :salaire ,  DESCFONCTION = :descfonction where idfonction = :aidfonction ;");

       qry.bindValue(":idfonction",IDFONCTION);
        qry.bindValue(":nomfonction",NOMFONCTION);
        qry.bindValue(":salaire",SALAIRE);
        qry.bindValue(":descfonction",DESCFONCTION);
        qry.bindValue(":aidfonction",AIDFONCTION);

        if (qry.exec())
        {

        QMessageBox::information(this,tr("Done"),tr("Modification faite avec succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void fonction::on_supprimer_f_clicked()
{
    click->play();
    QAbstractItemModel * m = ui->comboBox_sup->model();
    QString whereClause = m->data(m->index(ui->comboBox_sup->currentIndex(),1)).toString();

    QSqlQuery * query = new QSqlQuery();
    query->prepare("delete from FONCTIONS where idfonction = :idfonction ;");
    query->bindValue(":idfonction",whereClause);
    if (query->exec())
        QMessageBox::information(this,tr("Done"),tr("Suppression faite avec succès"));
    else
        QMessageBox::critical(this,tr("Sorry"),tr("Error"));
}
