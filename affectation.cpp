#include "affectation.h"
#include "ui_affectation.h"
#include "gestion_affectation.h"
#include "materiel.h"
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
affectation::affectation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affectation)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());
    ui->comboBox_cin->setModel(tmpmat.afficher_CINlist());
    ui->comboBox_materiel->setModel(tmpmat.afficher_Mlist());
    ui->cx_id_affectation->setEnabled(1);

}

affectation::~affectation()
{
    delete ui;

}
void affectation::init()
{ui->cx_id_affectation->clear();}

//ajouter affectation


void affectation::on_pushButton_clicked()
{
    QString IDAFFECTATION,CIN,IDMATERIEL;
    IDAFFECTATION=ui->cx_id_affectation->text();
    CIN=ui->comboBox_cin->currentText();
    IDMATERIEL=ui->comboBox_materiel->currentText();
    QString NOMMATERIEL,MARQUEMATERIEL,DESCMATERIEL,IDCATEGORIE,IMAGE,IDFOURNISSUER;
    int PRIXMATERIEL,STOCKMATERIEL;
    gestion_affectation A(IDAFFECTATION,CIN,IDMATERIEL);
    gestion_materiel M(IDMATERIEL,NOMMATERIEL,MARQUEMATERIEL,PRIXMATERIEL,STOCKMATERIEL,DESCMATERIEL,IDCATEGORIE,IMAGE,IDFOURNISSUER);

    if(A.verif_idAF(A.get_idAF())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter constructeur"),
                              QObject::tr(" IdC doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        bool test=A.ajouter_Affectation();
        if(test)
        {
            bool test=tmpaff.Modifier_Stock(M);
            QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueAffectation.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nAffectation a été ajoutée sous :\n idA:"+IDAFFECTATION+" \n CIN:"+CIN+" \n idM:"+IDMATERIEL ;
            cout << message2;
            sa.speak();//ajouter speak
            init();
            ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());
            ui->label_5->setText("Ajouter Affectation");

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Catégorie "),
                                  QObject::tr("Catégorie existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}
//afficher affectation
void affectation::on_pushButton_2_clicked()
{
    ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());
    ui->label_5->setText("Afficher Affectation");
    init();
}
//tableau cliced
void affectation::on_afficher_affectation_activated(const QModelIndex &index)
{
    QString val=ui->afficher_affectation->model()->data(index).toString();
    QSqlQuery qry ;
    qry=tmpaff.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_id_affectation->setDisabled(1);
            ui->cx_id_affectation->setText(qry.value(0).toString());
            ui->comboBox_cin->setCurrentText(qry.value(1).toString());
            ui->comboBox_materiel->setCurrentText(qry.value(2).toString());
            ui->label_5->setText("Affectaion selectionner");
        }
    }
}
//suprimer affectation
void affectation::on_pushButton_3_clicked()
{
    QString idA = ui->cx_id_affectation->text();

    bool test=tmpaff.supprimer_Affectation(idA);
    if(test)
    {    ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());


        ui->label_5->setText("Supprimer Affectation ");
        ui->cx_id_affectation->setEnabled(1);
        //ss.speak();//speak supprimer
        init();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Catégorie"),
                              QObject::tr("verifier l'id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
//modifier Affectation
void affectation::on_pushButton_4_clicked()
{
    QString IDAFFECTATION = ui->cx_id_affectation->text();

    QString CIN = ui->comboBox_cin->currentText();
    QString  IDMATERIEL = ui->comboBox_materiel->currentText();



    gestion_affectation A(IDAFFECTATION,CIN,IDMATERIEL);
    bool test=tmpaff.modifier_Affectation(A);
    if(test)
    {

        ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());
        ui->label_5->setText("Modifier Affectation ");
        //sm.speak();
        init();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Matériel"),
                              QObject::tr("Matériel non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
//trier selon id Affectation  croissant
void affectation::on_radioButton_clicked()
{
    ui->afficher_affectation->setModel(tmpaff.afficher_idCroissant());
    ui->label_5->setText("Tri Croissant par idA ");
}
//trier selon id Affectation decroissant
void affectation::on_radioButton_3_clicked()
{
    ui->afficher_affectation->setModel(tmpaff.afficher_idDecroissant());
    ui->label_5->setText("Tri Decroissant par idA ");
}
//trier selon id materiel croissant
void affectation::on_radioButton_2_clicked()
{
    ui->afficher_affectation->setModel(tmpaff.afficher_idMaterielCroissant());
    ui->label_5->setText("Tri Croissant par idM ");
}
//trier selon id materiel decroissant
void affectation::on_radioButton_4_clicked()
{
    ui->afficher_affectation->setModel(tmpaff.afficher_idMaterielDecroissant());
    ui->label_5->setText("Tri deCroissant par idM ");
}
//recherche
void affectation::on_pushButton_5_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from affectationmateriaux where IDAFFECTATION like '"+ui->Recherche->text()+"' OR CIN like '"+ui->Recherche->text()+"' OR IDMATERIEL like '"+ui->Recherche->text()+"' ");
    tmpaff.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_affectation->setModel(tmpaff.rechercher(q)) ;
    ui->label_5->setText("Chrecher");
}



