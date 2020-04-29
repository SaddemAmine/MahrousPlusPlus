#include "categorie_plante.h"
#include "ui_categorie_plante.h"
#include "gestion_categorie_plante.h"
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

categorie_plante::categorie_plante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categorie_plante)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());
    //refreche mil lawel



}

categorie_plante::~categorie_plante()
{
    delete ui;
}
//fonction hethi wael init de tel facon traja3lek les champs fer8a ki tajouti waela tmidifi ajoutiha
void categorie_plante::init()
{
    ui->cx_idcategorie->clear();
    ui->cx_nomcategorie->clear();
    ui->lineEdit_recherche->clear();
}
//ajout
void categorie_plante::on_pushButton_clicked()
{
    QString IDCATEGORIEPLANTE,NOMCATEGORIEPLANTE;
    IDCATEGORIEPLANTE=ui->cx_idcategorie->text();
    NOMCATEGORIEPLANTE=ui->cx_nomcategorie->text();


    gestion_categorie_plante C(IDCATEGORIEPLANTE,NOMCATEGORIEPLANTE);
//controle de saisie bech n5arajhom fonction bech na3emlelhom il appel fil modif

    if(C.verif_vide(C.get_idC())==false  )
    {
        ui->remarque_id->setText("*");
        //ui->remarque_nom->setText("*");
        ui->text_vide->setText("Tous les champs sont nécessaire");
    }

    if (C.verif_vide(C.get_nomC())==false )
    {
        ui->remarque_nom->setText("*");
        ui->text_vide->setText("Tous les champs sont nécessaire");
    }
    if (C.verif_vide(C.get_idC())==true && C.verif_vide(C.get_nomC())==true )
    {
        ui->text_vide->hide();
    }

    if (C.verif_idC(C.get_idC())==false)
    {
        ui->remarque_id->setText("*");
        ui->text_chiffre->setText("Il faut que l'id soit un chiffre ");
    }
    else {
        ui->remarque_id->hide();
        ui->text_chiffre->hide();
    }

    if (C.verif_Nom(C.get_nomC())==false)
    {
        ui->remarque_nom->setText("*");
        ui->text_lettres->setText("Il faut que le nom soit un lettres ");
    }else if(C.verif_Nom(C.get_nomC())==true){
        ui->remarque_nom->hide();
        ui->text_lettres->hide();
    }

    if (C.verif_Nom(C.get_nomC())==true && C.verif_idC(C.get_idC())==true && C.verif_vide(C.get_nomC())==true  && C.verif_vide(C.get_idC())==true )
    {
        bool test=C.ajouter_Categorie();

        if(test)
        {
            // ui->text_id->hide();
            QFile file("A:\\qt\\gestionmateriaux\\Historiqueespece.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\n Catégorie a été ajoutée sous l'id :"+IDCATEGORIEPLANTE+" et sous le nom : "+NOMCATEGORIEPLANTE+"";
            cout << message2;
            //d.speak();//speak ajout


            init();
            ui->label_3->setText("Catégorie ajouté");
            //ba3ed il ajout refr
            //ui->comboBox_supp->setModel(tmpcat.afficher_Clist());
            ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Catégorie "),
                                  QObject::tr("Catégorie existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}
//supprimer
void categorie_plante::on_pushButton_2_clicked()
{
    QString idC = ui->cx_idcategorie->text();
    bool test=tmpcat.supprimer_Categorie(idC);
    if(test)
    {    ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());
   //refresh

         ui->label_3->setText("Supprimer Catégorie");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Catégorie"),
                    QObject::tr("verifier l'id  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
//modif
void categorie_plante::on_pushButton_3_clicked()
{

    QString IDCATEGORIEPLANTE = ui->cx_idcategorie->text();
    QString NOMCATEGORIEPLANTE= ui->cx_nomcategorie->text();


gestion_categorie_plante C(IDCATEGORIEPLANTE,NOMCATEGORIEPLANTE);
bool test=tmpcat.modifier_Categorie(C);
if(test)
{

    ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());//refresh
     //refreshhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh

    ui->label_3->setText("Modifier Catégorie");

}
else
{
    QMessageBox::critical(nullptr, QObject::tr("Modifier Catégorie"),
                QObject::tr("Catégorie non valide  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}




//affich
void categorie_plante::on_pushButton_6_clicked()
{
    ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());//refresh
     //refresh

}

void categorie_plante::on_afficher_categorie_activated(const QModelIndex &index)
{
    QString val=ui->afficher_categorie->model()->data(index).toString();
    QSqlQuery qry ;

    qry.prepare("Select * from CATEGORIESPLANTES where NOMCATEGORIEPLANTE='"+val+"' ");
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idcategorie->setDisabled(1);
            ui->cx_idcategorie->setText(qry.value(0).toString());
            ui->cx_nomcategorie->setText(qry.value(1).toString());
        }
    }
}
void categorie_plante::on_pushButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from CATEGORIESPLANTES where IDCATEGORIEPLANTE like '"+ui->lineEdit_recherche->text()+"' OR NOMCATEGORIEPLANTE like '"+ui->lineEdit_recherche->text()+"'  ");
         tmpcat.rechercher(q) ;
           q.exec();
           model->setQuery(q);
           ui->afficher_categorie->setModel(tmpcat.rechercher(q)) ;
           ui->label_3->setText("Chercher");
}



void categorie_plante::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CATEGORIESPLANTES ORDER BY NOMCATEGORIEPLANTE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Catégorie "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Catégorie"));

    ui->afficher_categorie->setModel(model) ;
        ui->label_3->setText("Trier A-Z");
}

void categorie_plante::on_radioButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CATEGORIESPLANTES ORDER BY NOMCATEGORIEPLANTE desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Catégorie "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Catégorie"));

ui->afficher_categorie->setModel(model) ;
    ui->label_3->setText("Trier Z-A");
}

void categorie_plante::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CATEGORIESPLANTES ORDER BY IDCATEGORIEPLANTE ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Catégorie "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Catégorie"));

ui->afficher_categorie->setModel(model) ;
    ui->label_3->setText("Trier Croissant du IdCatégorie");
}

void categorie_plante::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CATEGORIESPLANTES ORDER BY IDCATEGORIEPLANTE desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Catégorie "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Catégorie"));

ui->afficher_categorie->setModel(model) ;
    ui->label_3->setText("Trier Décroissant du IdCatégorie");
}
