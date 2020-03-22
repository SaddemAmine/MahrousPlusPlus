#include "personnel.h"
#include "ui_personnel.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
#include <QDebug>
personnel::personnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personnel)
{
    ui->setupUi(this);
    qApp->setStyle(QStyleFactory::create("Fusion"));
        QPixmap pix("F:/Esprit/year_2/qt/projects/crud/resources/template.png");
        int w =ui->pic->width();
        int h =ui->pic->height();

          ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
       // ui->status->setText("Connected...");
      timer = new QTimer(this);
      connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
      timer->start(1000);

      click = new QMediaPlayer();
      click->setMedia(QUrl::fromLocalFile("A:/PROJET QT/crud/click.mp3"));

      //comboBox ajouter
      QSqlQueryModel * model = new QSqlQueryModel();
      QSqlQuery * query = new QSqlQuery();
      query->prepare("select nomfonction,idfonction from fonctions;");
      query->exec();
      model->setQuery(*query);
      ui->comboBox->setModel(model);
      ui->comboBox_3->setModel(model);
      // --

      //comboBox modifer
      QSqlQueryModel * model2 = new QSqlQueryModel();
      QSqlQuery * query2 = new QSqlQuery();
      query2->prepare("select nompersonnel||' '||prenompersonnel||', '||cin,cin,idfonction from personnels;");
      query2->exec();
      model2->setQuery(*query2);
      ui->comboBox_4->setModel(model2);
      ui->comboBox_5->setModel(model2);
      // --
}

personnel::~personnel()
{
    delete ui;
}

void personnel::on_comboBox_currentIndexChanged()
{
    QAbstractItemModel * m = ui->comboBox->model();
    qDebug()<<"test "<< m->data(m->index(ui->comboBox->currentIndex(),1))<< m->data(m->index(ui->comboBox->currentIndex(),0));
}

void personnel::on_pushButton_p_clicked(){
    click->play();
    QString CIN,NOMPERSONNEL,PRENOMPERSONNEL,ADRESSE,DATEEMBAUCHE,IDFONCTION;
    CIN=ui->cx_cin->text();
    NOMPERSONNEL=ui->cx_nompersonnel->text();
    PRENOMPERSONNEL=ui->cx_prenompersonnel->text();
    ADRESSE=ui->cx_adresse->text();
    DATEEMBAUCHE=ui->cx_date->text();
    QAbstractItemModel * m = ui->comboBox->model();
    IDFONCTION = m->data(m->index(ui->comboBox->currentIndex(),1)).toString();
    QSqlQuery qry;
    qDebug() << qry.prepare("INSERT into PERSONNELS values (:cin , :nom , :prenom , :adr , :date , :idf)");
    qry.bindValue(":cin",CIN);
    qry.bindValue(":nom",NOMPERSONNEL);
    qry.bindValue(":prenom",PRENOMPERSONNEL);
    qry.bindValue(":adr",ADRESSE);
    qry.bindValue(":date",DATEEMBAUCHE);
    qry.bindValue(":idf",IDFONCTION);
    if (qry.exec())
    {

    QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void personnel::on_pushButton_2_f_clicked()
{
    click->play();
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from PERSONNELS");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}

void personnel::on_comboBox_4_currentIndexChanged()
{
    QAbstractItemModel * m = ui->comboBox_4->model();
    QString whereClause = m->data(m->index(ui->comboBox_4->currentIndex(),1)).toString();

    QSqlQuery * modquery1 = new QSqlQuery();
    QSqlQuery * modquery2 = new QSqlQuery();

    modquery1->prepare("select * from personnels where cin = '"+whereClause+"';");
    modquery1->exec();
    modquery2->prepare("select nomfonction from fonctions where idfonction = '"+m->data(m->index(ui->comboBox_4->currentIndex(),2)).toString()+"';");
    modquery2->exec();

    while(modquery1->next()){
        ui->cx_cinmod->setText(modquery1->value("cin").toString());
        ui->cx_nompersonnel_3->setText(modquery1->value("nompersonnel").toString());
        ui->cx_prenompersonnel_3->setText(modquery1->value("prenompersonnel").toString());
        ui->cx_adresse_3->setText(modquery1->value("adresse").toString());
        ui->cx_date_3->setDate(modquery1->value("dateembauche").toDate());

        while(modquery2->next())
            ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(modquery2->value("nomfonction").toString()));
    }
}

void personnel::on_modifier_f_clicked()
{   QAbstractItemModel * m4 = ui->comboBox_4->model();
    QString ACIN,CIN,NOMPERSONNEL,PRENOMPERSONNEL,ADRESSE,DATEEMBAUCHE,IDFONCTION;

    ACIN = m4->data(m4->index(ui->comboBox_4->currentIndex(),1)).toString();//ancien CIN
    CIN=ui->cx_cinmod->text();
    NOMPERSONNEL=ui->cx_nompersonnel_3->text();
    PRENOMPERSONNEL=ui->cx_prenompersonnel_3->text();
    ADRESSE=ui->cx_adresse_3->text();
    DATEEMBAUCHE=ui->cx_date_3->text();
    QAbstractItemModel * m = ui->comboBox_3->model();
    IDFONCTION = m->data(m->index(ui->comboBox_3->currentIndex(),1)).toString();

    QSqlQuery qry;
    qDebug() << qry.prepare("update PERSONNELS set cin = :cin , nompersonnel = :nom , prenompersonnel = :prenom , adresse = :adr , dateembauche = :date , idfonction = :idf where cin = :acin ;");
    qry.bindValue(":cin",CIN);
    qry.bindValue(":nom",NOMPERSONNEL);
    qry.bindValue(":prenom",PRENOMPERSONNEL);
    qry.bindValue(":adr",ADRESSE);
    qry.bindValue(":date",DATEEMBAUCHE);
    qry.bindValue(":idf",IDFONCTION);
    qry.bindValue(":acin",ACIN);

    if (qry.exec())
    {

    QMessageBox::information(this,tr("Done"),tr("Modification faite avec succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void personnel::on_supprimer_f_clicked()
{
    QAbstractItemModel * m = ui->comboBox_5->model();
    QString whereClause = m->data(m->index(ui->comboBox_5->currentIndex(),1)).toString();

    QSqlQuery * query = new QSqlQuery();
    query->prepare("delete from personnels where cin = :cin ;");
    query->bindValue(":cin",whereClause);
    if (query->exec())
        QMessageBox::information(this,tr("Done"),tr("Suppression faite avec succès"));
    else
        QMessageBox::critical(this,tr("Sorry"),tr("Error"));
}
