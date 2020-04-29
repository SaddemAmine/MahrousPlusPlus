#include "plante.h"
#include "ui_plante.h"
#include "gestion_plante.h"
#include"categorie_plante.h"
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

plante::plante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plante)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_plante->setModel(tmppl.afficher_plante());
    //ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
    ui->comboBox_categorie->setModel(tmpcat.afficher_Clist());
    ui->cx_idp->setEnabled(1);

}

plante::~plante()
{
    delete ui;
}

void plante::init()
{
    ui->cx_idp->clear();
   // ui->cx_idc->clear();
    ui->photo->clear();
    ui->chemin->clear();
    //ui->recherche->clear();
    ui->cx_quant->clear();
    ui->cx_etat->clear();
    ui->cx_secteur->clear();


}

//ajouter
void plante::on_pushButton_clicked()
{


    QString IDPLANTE = ui->cx_idp->text();
    QString SECTEUR= ui->cx_secteur->text();

    int QUANTITE = ui->cx_quant->text().toInt();
    QString ETAT= ui->cx_etat->text();
    QString IDCATEGORIEPLANTE = ui->comboBox_categorie->currentText();
    QString IMG =ui->chemin->text();//LABEL CHEMIN
   /* QAbstractItemModel * a = ui->comboBox_categorie->model();
    QString IDCATEGORIE= a->data(a->index(ui->comboBox_categorie->currentIndex(),1)).toString();*/
    gestion_plante P(IDPLANTE,SECTEUR,QUANTITE,ETAT,IDCATEGORIEPLANTE,IMG);


    if(P.verif_id(P.get_idP())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Plante"),
                              QObject::tr(" Id doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }else if(P.verif_secteur(P.get_secteur())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Plante"),
                              QObject::tr(" secteur doit contenir 5 caractéres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else{

        bool test=P.ajouter_plante();
        if(test)
        {   ui->label_8->setText("Ajouter Plante");
            QFile file("A:\\qt\\gestionmateriaux\\MATERIEL.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\n L'historique des Personnels à ajouter :"+IDPLANTE+" "+SECTEUR+"  "+QUANTITE+" "+ETAT+" "+IDCATEGORIEPLANTE+" "+IMG ;
            cout << message2;
            ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh
            //ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
            init();
            //ui->comboBox_mail->setModel(tmppers.getMailModel());

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Plante"),
                                  QObject::tr("Plante existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}

//ajouter photo
void plante::on_pushButton_5_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin->setText(filename);
            image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
            ui->photo->setPixmap(QPixmap::fromImage(image));
        }

    }
}
//affichage
void plante::on_pushButton_9_clicked()
{
    ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh
  //  ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
}


void plante::on_afficher_plante_activated(const QModelIndex &index)
{
    QString val=ui->afficher_plante->model()->data(index).toString();
    QSqlQuery qry ;

    qry.prepare("Select * from PLANTES where IDPLANTE='"+val+"' ");

    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idp->setDisabled(1);
            ui->cx_idp->setText(qry.value(0).toString());
            ui->cx_secteur->setText(qry.value(1).toString());
            ui->cx_quant->setText(qry.value(3).toString());
            ui->cx_etat->setText(qry.value(2).toString());
            ui->comboBox_categorie->setCurrentText(qry.value(4).toString());
            ui->chemin->setText(qry.value(5).toString());
            QPixmap pix(ui->chemin->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
}

//supprimer
void plante::on_pushButton_2_clicked()
{
    QString idP = ui->cx_idp->text();
            //on_pushButton_4_clicked();
    bool test=tmppl.supprimer_plante(idP);
    if(test)
    {    ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh
       // ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
        ui->label_8->setText("Supprimer Plante ");
        init();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Plante"),
                              QObject::tr("verifier le id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

//modifier
void plante::on_pushButton_3_clicked()
{
    QString IDPLANTE = ui->cx_idp->text();
    QString SECTEUR= ui->cx_secteur->text();
    int QUANTITE = ui->cx_quant->text().toInt();
    QString ETAT= ui->cx_etat->text();
    QString IDCATEGORIEPLANTE = ui->comboBox_categorie->currentText();
    QString IMG= ui->chemin->text();//LABEL CHEMIN



    gestion_plante P(IDPLANTE,SECTEUR,QUANTITE,ETAT,IDCATEGORIEPLANTE,IMG);
    bool test=tmppl.modifier_plante(P);
    if(test)
    {

        ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh
        //ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
        ui->label_8->setText("Modifier plante");
        init();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier plante"),
                              QObject::tr("plante non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
//recherche
void plante::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from PLANTES where IDPLANTE like '"+ui->recherche->text()+"' OR SECTEUR like '"+ui->recherche->text()+"' OR ETAT like '"+ui->recherche->text()+"' ");
    tmppl.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_plante->setModel(tmppl.rechercher(q)) ;
    ui->label_8->setText("Chrecher");
}

void plante::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PLANTES ORDER BY SECTEUR ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Secteur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IdCat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));


    ui->afficher_plante->setModel(model) ;
    ui->label_8->setText("Tri A-Z");
}

void plante::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PLANTES ORDER BY SECTEUR DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Secteur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IdCat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));



    ui->afficher_plante->setModel(model) ;
    ui->label_8->setText("Tri Z-A");
}

void plante::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PLANTES ORDER BY QUANTITE desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Secteur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IdCat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));


    ui->afficher_plante->setModel(model) ;
    ui->label_8->setText("Tri Décroissant du Quantite");
}

void plante::on_radioButton_5_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PLANTES ORDER BY QUANTITE  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Secteur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IdCat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));


    ui->afficher_plante->setModel(model) ;
    ui->label_8->setText("Tri Croissant du Quantite");
}

void plante::on_pushButton_10_clicked()
{
    s=new Stat_plante(this);
    s->show();
}
