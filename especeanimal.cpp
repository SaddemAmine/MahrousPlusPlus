#include "especeanimal.h"
#include "ui_especeanimal.h"
#include "gestion_especeanimal.h"

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

especeanimal::especeanimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::especeanimal)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_especeanimal->setModel(tmpcat.afficher_especeanimal());
    ui->cx_idespeceanimal->setEnabled(1);

}

especeanimal::~especeanimal()
{
    delete ui;
}
void especeanimal::init()
{
    ui->cx_idespeceanimal->clear();
    ui->cx_nomespeceanimal->clear();
    ui->lineEdit_recherche->clear();
}

//ajout
void especeanimal::on_pushButton_clicked()
{
    QString IDESPECE,NOMESPECE;
    IDESPECE=ui->cx_idespeceanimal->text();
    NOMESPECE=ui->cx_nomespeceanimal->text();


    gestion_especeanimal C(IDESPECE,NOMESPECE);
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
        bool test=C.ajouter_especeanimal();

        if(test)
        {

            QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueEspeceAnimal.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nEspece Animale a été ajoutée sous :\nidEA :"+IDESPECE+"\nnom : "+NOMESPECE+"";
            cout << message2;
            sa.speak();//speak ajout


            init();
            ui->label_3->setText("Espéce ajouté");

            ui->afficher_especeanimal->setModel(tmpcat.afficher_especeanimal());

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
void especeanimal::on_pushButton_2_clicked()
{
    QString idC = ui->cx_idespeceanimal->text();

    bool test=tmpcat.supprimer_especeanimal(idC);
    if(test)
    {    ui->afficher_especeanimal->setModel(tmpcat.afficher_especeanimal());
        ui->label_3->setText("Supprimer Espéce");
        ui->cx_idespeceanimal->setEnabled(1);
        //ss.speak();//speak supprimer
        init();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Catégorie"),
                              QObject::tr("verifier l'id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
//modif
void especeanimal::on_pushButton_3_clicked()
{

    QString IDESPECE = ui->cx_idespeceanimal->text();

    QString NOMESPECE= ui->cx_nomespeceanimal->text();


    gestion_especeanimal C(IDESPECE,NOMESPECE);
    bool test=tmpcat.modifier_especeanimal(C);
    if(test)
    {

        ui->afficher_especeanimal->setModel(tmpcat.afficher_especeanimal());//refresh

        ui->label_3->setText("Modifier Espéce");
        ui->cx_idespeceanimal->setEnabled(1);
        //sm.speak();//speak modif
        init();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Catégorie"),
                              QObject::tr("Catégorie non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



//recherche
void especeanimal::on_pushButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from ESPECESANIMAUX where IDESPECE like '"+ui->lineEdit_recherche->text()+"' OR NOMESPECE like '"+ui->lineEdit_recherche->text()+"'  ");
    tmpcat.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_especeanimal->setModel(tmpcat.rechercher(q)) ;
    ui->label_3->setText("Chercher");
}
//refreche
void especeanimal::on_pushButton_6_clicked()
{
    ui->afficher_especeanimal->setModel(tmpcat.afficher_especeanimal());//refresh
    ui->label_3->setText("Afficher la liste des Espéces");
    //ui->comboBox_supp->setModel(tmpcat.afficher_Clist());
}
//trie selon nomespece croissant
void especeanimal::on_radioButton_3_clicked()
{

    ui->afficher_especeanimal->setModel(tmpcat.afficher_nomCroissant());//refresh

    ui->label_3->setText("Trier A-Z");
}
//trie selon nomespece decroissant
void especeanimal::on_radioButton_4_clicked()
{
    ui->afficher_especeanimal->setModel(tmpcat.afficher_nomDecroissant());//refresh
    ui->label_3->setText("Trier Z-A");
}
//trie selon idespece croissant
void especeanimal::on_radioButton_clicked()
{

    ui->afficher_especeanimal->setModel(tmpcat.afficher_idCroissant());//refresh
    ui->label_3->setText("Trier Croissant du IdCatégorie");
}
//trie selon idespece decroissant
void especeanimal::on_radioButton_2_clicked()
{
    ui->afficher_especeanimal->setModel(tmpcat.afficher_idDecroissant());//refresh
    ui->label_3->setText("Trier Décroissant du IdCatégorie");
}

//selection de table
void especeanimal::on_afficher_especeanimal_activated(const QModelIndex &index)
{
    QString val=ui->afficher_especeanimal->model()->data(index).toString();
    QSqlQuery qry ;

    // qry.prepare("Select * from ESPECESANIMAUX where nomespece='"+val+"' ");
    qry=tmpcat.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idespeceanimal->setDisabled(1);
            ui->cx_idespeceanimal->setText(qry.value(0).toString());
            ui->cx_nomespeceanimal->setText(qry.value(1).toString());
            ui->label_3->setText("Ecpéce Selectionée");
        }
    }

}



