#include "besoin_plante.h"
#include "ui_besoin_plante.h"
#include "gestion_besoin_plante.h"
#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QProgressBar>
#include <QStatusBar>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <windows.h>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
besoin_plante::besoin_plante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::besoin_plante)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());
    ui->cx_idbp->setEnabled(1);
}

besoin_plante::~besoin_plante()
{
    delete ui;
}
void besoin_plante::init()
{
   // ui->cx_eaup->clear();
    ui->cx_idbp->clear();
    ui->cx_nutp->clear();
    ui->recherche->clear();

}
//ajouter besoin plante
void besoin_plante::on_pushButton_clicked()
{
    QString idB,np;
    int ep;
    idB=ui->cx_idbp->text();
    np=ui->cx_nutp->text();

    //ep=ui->Eau->text().toInt();
    gestion_besoin_plante B(idB,ep,np);




    if(B.verif_idB(B.get_idB())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Besoin plante"),
                              QObject::tr(" Id doit etre unique !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else{

        bool test=B.ajouter_besoin_plante();
        if(test)
        {   ui->label_5->setText("Ajouter Besoin Plante");
            QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueBesoinPlantes.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nBesoin Plante a été ajoutée sous:\nIdBP:"+idB+"\nNutrition:"+np+"\neau:"+ep ;
            cout << message2;
            ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());//refresh

            init();

            sa.speak();//speek ajout

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                                  QObject::tr("Matériel existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}
//table clicked
void besoin_plante::on_afficher_besoin_palnte_activated(const QModelIndex &index)
{
    QString val=ui->afficher_besoin_palnte->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tmpbp.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idbp->setDisabled(1);
            ui->cx_idbp->setText(qry.value(0).toString());
            ui->Eau->setValue(qry.value(1).toInt());
            ui->cx_nutp->setText(qry.value(2).toString());
            ui->label_5->setText("Besoin Plante Selectionée");
        }
    }
}

//supprimer besoin Plante
void besoin_plante::on_pushButton_3_clicked()
{
    QString idB = ui->cx_idbp->text();

    bool test=tmpbp.supprimer_besoin_plante(idB);
    if(test)
    {    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());

        ui->label_5->setText("Supprimer Besoin Plante");
        ui->cx_idbp->setEnabled(1);
        ss.speak();//speak supprimer
        init();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Catégorie"),
                              QObject::tr("verifier l'id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
//modifier besoin plante
void besoin_plante::on_pushButton_2_clicked()
{

    QString idB,np;
    int ep;
    idB=ui->cx_idbp->text();
    np=ui->cx_nutp->text();

    ep=ui->Eau->text().toInt();
    gestion_besoin_plante B(idB,ep,np);

    bool test=tmpbp.modifier_besoin_plante(B);
    if(test)
    {

        ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());//refresh

        ui->label_5->setText("Modifier Besoin Plante");
        init();
        sm.speak();//speek modifier
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Matériel"),
                              QObject::tr("Matériel non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
//trier croissant idbp
void besoin_plante::on_radioButton_clicked()
{

    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_idCroissant());
     ui->label_5->setText("Tri Croissant par idBP ");
}
//trier croissant quantite d'eau
void besoin_plante::on_radioButton_2_clicked()
{

    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_EauCroissant());
     ui->label_5->setText("Tri Croissant par Quantite D'eau ");
}
//trier croissant Nutrition
void besoin_plante::on_radioButton_3_clicked()
{

    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_NutCroissant());
     ui->label_5->setText("Tri Croissant par Quantite de Nutrition ");
}
//trier decroissant idbp
void besoin_plante::on_radioButton_4_clicked()
{

    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_idDecroissant());
     ui->label_5->setText("Tri Decroissant par idBP ");
}
//Tri Decroissant par Quantite D'eau
void besoin_plante::on_radioButton_5_clicked()
{
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_EauDecroissant());
     ui->label_5->setText("Tri Decroissant par Quantite D'eau ");
}
//Tri Decroissant par Quantite de Nutrition
void besoin_plante::on_radioButton_6_clicked()
{
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_NutDecroissant());
     ui->label_5->setText("Tri Decroissant par Quantite de Nutrition ");
}

void besoin_plante::on_pushButton_5_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from BESOINSPLANTES where IDBESOINSPLANTE like '"+ui->recherche->text()+"' OR NUTRITIONPLANTE like '"+ui->recherche->text()+"' OR EAUPLANTE like '"+ui->recherche->text()+"' ");
    tmpbp.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_besoin_palnte->setModel(tmpbp.rechercher(q)) ;
    ui->label_5->setText("Recherche");
}
//afficher
void besoin_plante::on_pushButton_4_clicked()
{
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());
    ui->label_5->setText("Afficher Besoin Plante");
    init ();
}
