#include "categorie_materiel.h"
#include "ui_categorie_materiel.h"

#include "gestion_categorie_materiel.h"

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

categorie_materiel::categorie_materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categorie_materiel)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());
    //refreche mil lawellllllllllllllllllllllllllllllllllllllllll

    //ui->comboBox_supp->setModel(tmpcat.afficher_Clist());
    ui->cx_idcategorie->setEnabled(1);
}

categorie_materiel::~categorie_materiel()
{
    delete ui;
}
void categorie_materiel::init()
{
    ui->cx_idcategorie->clear();
    ui->cx_nomcategorie->clear();
    ui->lineEdit_recherche->clear();
}
void categorie_materiel::test( gestion_categorie_materiel C)
{



    if(C.verif_vide(C.get_idC())==false  )
    {
        ui->remarque_id->setText("*");
        //ui->cx_idcategorie->
        //ui->text_vide->setText("Tous les champs sont nécessaire");
//ui->cx_idcategorie->setStyleSheet("background: red");
    }

    if (C.verif_vide(C.get_nomC())==false )
    {
        ui->remarque_nom->setText("*");
        //ui->text_vide->setText("Tous les champs sont nécessaire");
       // ui->cx_nomcategorie->setStyleSheet("background: red");
    }


    if (C.verif_idC(C.get_idC())==false)
    {
        ui->remarque_id->setText("*");
        ui->text_chiffre->setText("Il faut que l'id soit un chiffre ");
    }
    else {
        ui->remarque_id->hide();
        ui->text_chiffre->hide();
        //ui->cx_idcategorie->setStyleSheet("background: white");
    }

    if (C.verif_Nom(C.get_nomC())==false)
    {
        ui->remarque_nom->setText("*");
        ui->text_lettres->setText("Il faut que le nom soit un lettres ");
    }else if(C.verif_Nom(C.get_nomC())==true){
        ui->remarque_nom->hide();
        ui->text_lettres->hide();
        // ui->cx_nomcategorie->setStyleSheet("background: white");
    }
}
//afficher categorie
void categorie_materiel::on_AfficherCategorieMateriel_clicked()
{
 ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());//refresh
 init();
 ui->cx_idcategorie->setEnabled(1);
 ui->label_3->setText("Afficher Catégorie");
}
//supprimer categorie
void categorie_materiel::on_SupprimerCategorieMateriel_clicked()
{

    QString idC = ui->cx_idcategorie->text();

    bool test=tmpcat.supprimer_Categorie(idC);
    if(test)
    {    ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());

        ui->label_3->setText("Supprimer Catégorie");
        ui->cx_idcategorie->setEnabled(1);
        //ss.speak();//speak supprimer
        init();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Catégorie"),
                              QObject::tr("verifier l'id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
//modifier categorie
void categorie_materiel::on_ModifierCategorieMaeriel_clicked()
{
    QString IDCATEGORIE = ui->cx_idcategorie->text();

    QString NOMCATEGORIE= ui->cx_nomcategorie->text();


    gestion_categorie_materiel C(IDCATEGORIE,NOMCATEGORIE);
    test(C);
     if (C.verif_Nom(C.get_nomC())==true && C.verif_idC(C.get_idC())==true && C.verif_vide(C.get_nomC())==true  && C.verif_vide(C.get_idC())==true )
     {
    bool test=tmpcat.modifier_Categorie(C);
    if(test)
    {

        ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());//refresh

        ui->label_3->setText("Modifier Catégorie");
        ui->cx_idcategorie->setEnabled(1);
        //sm.speak();//speak modif
        init();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Catégorie"),
                              QObject::tr("Catégorie non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }}
}
//ajouter categorie
void categorie_materiel::on_AjouterCategorieMateriel_clicked()
{

    QString IDCATEGORIE,NOMCATEGORIE;
    IDCATEGORIE=ui->cx_idcategorie->text();
    NOMCATEGORIE=ui->cx_nomcategorie->text();


    gestion_categorie_materiel C(IDCATEGORIE,NOMCATEGORIE);


test( C);

    if (C.verif_Nom(C.get_nomC())==true && C.verif_idC(C.get_idC())==true && C.verif_vide(C.get_nomC())==true  && C.verif_vide(C.get_idC())==true )
    {
        bool test=C.ajouter_Categorie();

        if(test)
        {

            QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueCategorieMateriel.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nCatégorie a été ajoutée sous :\n idC :"+IDCATEGORIE+" \n nomC : "+NOMCATEGORIE+"";
            cout << message2;
           sa.speak();//speak ajout


            init();
            ui->label_3->setText("Catégorie ajouté");

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
//table clicked
void categorie_materiel::on_afficher_categorie_activated(const QModelIndex &index)
{
    QString val=ui->afficher_categorie->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tmpcat.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idcategorie->setDisabled(1);
            ui->cx_idcategorie->setText(qry.value(0).toString());
            ui->cx_nomcategorie->setText(qry.value(1).toString());
            ui->label_3->setText("Categorie Selectionnée");
        }
    }
}
//Trier Croissant du IdCatégorie
void categorie_materiel::on_trieridcroi_clicked()
{


   ui->afficher_categorie->setModel(tmpcat.afficher_idCroissant());//refresh
    ui->label_3->setText("Trier Croissant du IdCatégorie");
}

//Trier Décroissant du IdCatégorie
void categorie_materiel::on_trieriddecroi_clicked()
{
    ui->afficher_categorie->setModel(tmpcat.afficher_idDecroissant());//refresh

    ui->label_3->setText("Trier Décroissant du IdCatégorie");
}
//Trier A-Z
void categorie_materiel::on_trierAZ_clicked()
{
    ui->afficher_categorie->setModel(tmpcat.afficher_nomCroissant());//refresh
    ui->label_3->setText("Trier A-Z");
}
//Trier Z-A
void categorie_materiel::on_trierZA_clicked()
{
   ui->afficher_categorie->setModel(tmpcat.afficher_nomDecroissant());//refresh


    ui->label_3->setText("Trier Z-A");
}
//recherche
void categorie_materiel::on_RechercheCategorieMateriel_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from CATEGORIESMATERIAUX where IDCATEGORIE like '"+ui->lineEdit_recherche->text()+"' OR NOMCATEGORIE like '"+ui->lineEdit_recherche->text()+"'  ");
    tmpcat.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_categorie->setModel(tmpcat.rechercher(q)) ;
    ui->label_3->setText("Chercher");
}
