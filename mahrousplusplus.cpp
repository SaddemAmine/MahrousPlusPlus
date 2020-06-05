#include "mahrousplusplus.h"
#include "ui_mahrousplusplus.h"
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
mahrousplusplus::mahrousplusplus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mahrousplusplus)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();

    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
   //fournisseur
    ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());

    ui->label_21->text();
    ui->cx_idf->setEnabled(1);
    ui->listView->hide();
    ui->listView2->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    //materiel
    ui->afficher_materiel->setModel(tmpmat.afficher_materiel());

    ui->comboBox_categorie->setModel(tmpcat.afficher_Clist());
    ui->comboBox_idf->setModel(tmpf.afficher_Flist());
    ui->cx_idm->setEnabled(1);

    ui->count->setStyleSheet("QLabel{min-width: 20px; min-height: 20px;max-width:20px; max-height: 16px;border-radius: 8px;  border:1px solid black;background:red;}");

   ui->count->setNum(tmpmat.afficher_count());
   ui->pushButton_17->hide();
   ui->afficher_materiel_insu->hide();
}

mahrousplusplus::~mahrousplusplus()
{
    delete ui;
}
void mahrousplusplus::init()
{
    ui->age->clear();
    ui->cx_idf->clear();
    ui->cx_tel->clear();
    ui->cx_nomf->clear();
    ui->cx_mailf->clear();
    //ui->femme->setChecked(false);
    ui->cx_prenomf->clear();
    ui->cx_recherche->clear();

}
//ajouter fournissuer
void mahrousplusplus::on_pushButton_clicked()
{
    QString IDFOURNISSEUR = ui->cx_idf->text();
    QString NOMFOURNISSEUR = ui->cx_nomf->text();
    QString PRENOMFOURNISSEUR = ui->cx_prenomf->text();
    int NUMTEL = ui->cx_tel->text().toInt();
    QString SEXE;
    int AGE= ui->age->text().toInt();
    if (ui->femme->isChecked())
    {
        SEXE="femme";
    }
    if (ui->homme->isChecked())
    {
        SEXE="homme";
    }

    QString MAIL = ui->cx_mailf->text();

    gestion_fournisseur_materiaux f(IDFOURNISSEUR,NOMFOURNISSEUR,PRENOMFOURNISSEUR,NUMTEL,AGE,SEXE, MAIL);

    if(f.verif_id(f.get_idf())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                              QObject::tr(" Id doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }

    else  {

        bool test=f.ajouter_fournisseur();
        if(test)
        {   ui->label_21->setText("Fournisseur AJOUTE");
            QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueFourniseur.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString res1= QString::number(AGE);
            QString res2= QString::number(NUMTEL);
            QString message2="\nFournisseur a été ajoutée sous :\nIdF :"+IDFOURNISSEUR+"\nnomF:"+NOMFOURNISSEUR+"\nprenomF: "+PRENOMFOURNISSEUR+"\nNumTel: "+res2+"\nage: "+res1+"\nsexe:"+SEXE+"\nmail:"+MAIL+ "";
            cout << message2;
            ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh

            ui->cx_idf->setEnabled(1);
            /*if (lng=="fr")
            {
            sa.ajouterf(NOMFOURNISSEUR);//speel ajout
            }
            else
            {
            sa.ajoutere(NOMFOURNISSEUR);
            }*/
            init();


        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un Personnel"),
                                  QObject::tr("Personnel existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}
//supprimer
void mahrousplusplus::on_pushButton_3_clicked()
{

    QString idf = ui->cx_idf->text();
    bool test=tmpf.supprimer_fournisseur(idf);
    if(test)
    {    ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh
        ui->listView->setModel(tmpf.afficher_Listemail());
        ui->listView2->setModel(tmpf.afficher_Listtel());
        ui->label_21->setText("Supprimer Fournisseur");
        ui->cx_idf->setEnabled(1);
        //ss.speak();//speek supprimer
        init();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Personnel"),
                              QObject::tr("verifier le cin  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
//afficher
void mahrousplusplus::on_pushButton_5_clicked()
{
    ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh
    ui->listView->setModel(tmpf.afficher_Listemail());
    ui->listView2->setModel(tmpf.afficher_Listtel());
    ui->label_21->setText("Afficher la liste des Fournisseurs");
    ui->cx_idf->setEnabled(1);
    init();
}
//modif
void mahrousplusplus::on_pushButton_4_clicked()
{
    QString IDFOURNISSEUR = ui->cx_idf->text();
    QString NOMFOURNISSEUR = ui->cx_nomf->text();
    QString PRENOMFOURNISSEUR = ui->cx_prenomf->text();
    int NUMTEL = ui->cx_tel->text().toInt();

    int AGE= ui->age->text().toInt();


    QString SEXE;
    if (ui->femme->isChecked())
    {
        SEXE="femme";
    }
    if (ui->homme->isChecked())
    {
        SEXE="homme";
    }
    QString MAIL = ui->cx_mailf->text();



    gestion_fournisseur_materiaux F(IDFOURNISSEUR,NOMFOURNISSEUR,PRENOMFOURNISSEUR,NUMTEL,AGE,SEXE, MAIL);
    bool test=tmpf.modifier_fournisseur(F);
    if(test)
    {

        ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh
        ui->listView->setModel(tmpf.afficher_Listemail());
        ui->listView2->setModel(tmpf.afficher_Listtel());
        ui->label_21->setText("Modifier Fournisseur");
        ui->cx_idf->setEnabled(1);
        //sm.speak();//speek modifier
        init();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Matériel"),
                              QObject::tr("Matériel non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
//Trier Croissant d'IdFournisseur
void mahrousplusplus::on_radioButton_clicked()
{



    ui->afficher_fournisseur->setModel(tmpf.afficher_idCroissant());//refresh
    ui->label_21->setText("Trier Croissant d'IdFournisseur");
}
//Trier Decroissant d'IdFournisseur
void mahrousplusplus::on_radioButton_2_clicked()
{
    ui->afficher_fournisseur->setModel(tmpf.afficher_idDecroissant());//refresh
    ui->label_21->setText("Trier Decroissant d'IdFournisseur");
}
//Trier Croissant d'Age
void mahrousplusplus::on_radioButton_5_clicked()
{



    ui->afficher_fournisseur->setModel(tmpf.afficher_AgeCroissant());//refresh
    ui->label_21->setText("Trier Croissant d'Age ");
}
//Trier Decroissant d'Age
void mahrousplusplus::on_radioButton_6_clicked()
{
    ui->afficher_fournisseur->setModel(tmpf.afficher_AgeDecroissant());//refresh
    ui->label_21->setText("Trier Decroissant d'Age");
}
//Trier A-Z du Nom
void mahrousplusplus::on_radioButton_3_clicked()
{

    ui->afficher_fournisseur->setModel(tmpf.afficher_NomCroissant());//refresh
    ui->label_21->setText("Trier A-Z du Nom");
}
//Trier Z-A du Nom
void mahrousplusplus::on_radioButton_4_clicked()
{
    ui->afficher_fournisseur->setModel(tmpf.afficher_NomDecroissant());//refresh


    ui->label_21->setText("Trier Z-A du Nom");
}
//Recherche
void mahrousplusplus::on_pushButton_6_clicked()
{
    QString q = ui->cx_recherche->text();

    if (q=="")
    {
        ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur()) ;

    }
    else {
        ui->afficher_fournisseur->setModel(tmpf.rechercher(q)) ;
        ui->label_21->setText("Chercher");
    }
}


//Statistique fournissuer
void mahrousplusplus::on_pushButton_10_clicked()
{
    f=new Statistique_fournisseur(this);
    f->show();
    ui->label_21->setText("Statistique Fournisseur ");
}
//table clicked
void mahrousplusplus::on_afficher_fournisseur_activated(const QModelIndex &index)
{
    QString val=ui->afficher_fournisseur->model()->data(index).toString();
    QSqlQuery qry ;

    qry =tmpf.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idf->setDisabled(1);
            ui->cx_idf->setText(qry.value(0).toString());
            ui->cx_nomf->setText(qry.value(1).toString());
            ui->cx_prenomf->setText(qry.value(2).toString());
            ui->cx_tel->setText(qry.value(3).toString());

            ui->age->setValue(qry.value(4).toInt());
            if (qry.value(5).toString()=="femme")
            {
                ui->femme->setChecked(true);

            }

            if (qry.value(5).toString()=="homme")
            {
                ui->homme->setChecked(true);
            }

            ui->cx_mailf->setText(qry.value(6).toString());
        }
    }
}

void mahrousplusplus::on_pushButton_2_clicked()
{
    ui->listView->show();
    ui->pushButton_17->show();
    ui->label_21->setText("Lister les email des fournisseurs.");
    ui->listView->setModel(tmpf.afficher_Listemail());

}

void mahrousplusplus::on_listView_activated(const QModelIndex &index)
{
    QString val = ui->listView->model()->data(index).toString();
    QSqlQuery qry ;

    qry =tmpf.listemailclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idf->setDisabled(1);
            ui->cx_idf->setText(qry.value(0).toString());
            ui->cx_nomf->setText(qry.value(1).toString());
            ui->cx_prenomf->setText(qry.value(2).toString());
            ui->cx_tel->setText(qry.value(3).toString());

            ui->age->setValue(qry.value(4).toInt());
            //ui->cx_sexef->hide();
            //ui->cx_sexef->setText();
            if (qry.value(5).toString()=="femme")
            {
                ui->femme->setChecked(true);

            }
            if (qry.value(5).toString()=="homme")
            {
                ui->homme->setChecked(true);
            }

            ui->cx_mailf->setText(qry.value(6).toString());
        }
        ui->label_21->setText("Mail selectionnée.");
    }
}

void mahrousplusplus::on_pushButton_17_clicked()
{
    ui->listView->hide();
    //ui->listView2->hide();
    ui->pushButton_17->hide();
    init();
}
void mahrousplusplus::on_pushButton_8_clicked()
{
    ui->listView2->show();
    ui->pushButton_18->show();

    ui->listView2->setModel(tmpf.afficher_Listtel());
    ui->label_21->setText("Lister les num tel des fournisseur");

}

/*void fournisseurs::on_pushButton_9_clicked()
{
   on_pushButton_8_clicked();
}
*/
void mahrousplusplus::on_listView2_activated(const QModelIndex &index)
{
    QString val = ui->listView2->model()->data(index).toString();
    QSqlQuery qry ;
    qry =tmpf.listtelclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idf->setDisabled(1);
            ui->cx_idf->setText(qry.value(0).toString());
            ui->cx_nomf->setText(qry.value(1).toString());
            ui->cx_prenomf->setText(qry.value(2).toString());
            ui->cx_tel->setText(qry.value(3).toString());

            ui->age->setValue(qry.value(4).toInt());
            //ui->cx_sexef->hide();
            //ui->cx_sexef->setText();
            if (qry.value(5).toString()=="femme")
            {
                ui->femme->setChecked(true);

            }
            if (qry.value(5).toString()=="homme")
            {
                ui->homme->setChecked(true);
            }

            ui->cx_mailf->setText(qry.value(6).toString());
        }
    }
}

void mahrousplusplus::on_pushButton_18_clicked()
{
    //ui->listView->hide();
    ui->listView2->hide();
    ui->pushButton_18->hide();
    init();
}

void mahrousplusplus::on_cx_recherche_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur()) ;

    }
}

void mahrousplusplus::on_pushButton_7_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);

}
void mahrousplusplus::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void mahrousplusplus::on_pushButton_9_clicked()
{

     ui->stackedWidget->setCurrentIndex(2);
}
void mahrousplusplus::on_pushButton_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}
void mahrousplusplus::on_pushButton_12_clicked()
{
    /*sa=new SpeekAjouter(this);
    sa.show();*/
}



