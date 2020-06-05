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
#include "photo.h"
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
    ui->comboBox_categorie->setModel(tmpcat.afficher_Clist());
    ui->comboBox_cin->setModel(tmppl.afficher_CINlist());
    ui->comboBox_IDBP->setModel(tmppl.afficher_IDBPlist());
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
    //ui->cx_quant->clear();
    //ui->cx_etat->clear();
    //ui->cx_secteur->clear();


}

//ajouter
void plante::on_pushButton_clicked()
{


    QString IDPLANTE = ui->cx_idp->text();
    QString SECTEUR;
    if (ui->Button_1->isChecked())
    {
        SECTEUR="1";
    }
    if (ui->Button_2->isChecked())
    {
        SECTEUR="2";
    }
    if (ui->Button_3->isChecked())
    {
        SECTEUR="3";
    }
    if (ui->Button_4->isChecked())
    {
        SECTEUR="4";
    }

    int QUANTITE = ui->Quantite->text().toInt();
    QString ETAT;
    if (ui->Mauvaise->isChecked())
    {
        ETAT="Mauvaise";
    }
    if (ui->Bonne->isChecked())
    {
        ETAT="Bonne";
    }
    QString IDCATEGORIEPLANTE = ui->comboBox_categorie->currentText();
    QString CIN=ui->comboBox_cin->currentText();
    QString IMG =ui->chemin->text();//LABEL CHEMIN
    QString IDBP=ui->comboBox_IDBP->currentText();
    gestion_plante P(IDPLANTE,SECTEUR,QUANTITE,ETAT,IDCATEGORIEPLANTE,IMG,CIN,IDBP);


    if(P.verif_id(P.get_idP())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Plante"),
                              QObject::tr(" Id doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else{

        bool test=P.ajouter_plante();
        if(test)
        {   ui->label_8->setText("Ajouter Plante");
            QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriquePlante.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nPlante a été ajoutée sous :\nidP:"+IDPLANTE+"\nSecteur: "+SECTEUR+"\nQuantite:  "+QUANTITE+"\nEtat: "+ETAT+"\nidCP :"+IDCATEGORIEPLANTE+"\n CheminPhoto: "+IMG+"\nCIN : "+CIN ;
            cout << message2;
            ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh

            init();

            sa.speak();//speek ajouter

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
             ui->label_8->setText("Ajouter Photo");
        }

    }
}
//modifier image
void plante::on_pushButton_4_clicked()
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
             ui->label_8->setText("Modifier Photo");
        }

    }
}

//affichage
void plante::on_pushButton_9_clicked()
{
    ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh
  ui->label_8->setText("Afficher la liste des plantes");
  init();
}

//table clicked
void plante::on_afficher_plante_activated(const QModelIndex &index)
{
    QString val=ui->afficher_plante->model()->data(index).toString();
    QSqlQuery qry ;


qry=tmppl.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idp->setDisabled(1);
            ui->cx_idp->setText(qry.value(0).toString());
            //ui->cx_secteur->setText(qry.value(1).toString());
            if (qry.value(1).toString()=="1")
            {
                ui->Button_1->setChecked(true);
            }
            if (qry.value(1).toString()=="2")
            {
                ui->Button_2->setChecked(true);
            }
            if (qry.value(1).toString()=="3")
            {
                ui->Button_3->setChecked(true);
            }
            if (qry.value(1).toString()=="4")
            {
                ui->Button_4->setChecked(true);
            }
            ui->Quantite->setValue(qry.value(3).toInt());
            //ui->cx_etat->setText(qry.value(2).toString());
            if (qry.value(2).toString()=="Mauvaise")
            {
                ui->Mauvaise->setChecked(true);

            }
            if (qry.value(2).toString()=="Bonne")
            {
                ui->Bonne->setChecked(true);
            }
            ui->comboBox_categorie->setCurrentText(qry.value(4).toString());
            ui->chemin->setText(qry.value(5).toString());
            QPixmap pix(ui->chemin->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            ui->comboBox_cin->setCurrentText(qry.value(6).toString());
             ui->comboBox_IDBP->setCurrentText(qry.value(7).toString());
        }
    }
}

//supprimer
void plante::on_pushButton_2_clicked()
{
    QString idP = ui->cx_idp->text();

    bool test=tmppl.supprimer_plante(idP);
    if(test)
    {    ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh

        ui->label_8->setText("Supprimer Plante ");
        init();
        //ss.speak();//speek supprimer
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
    QString SECTEUR;
    if (ui->Button_1->isChecked())
    {
        SECTEUR="1";
    }
    if (ui->Button_2->isChecked())
    {
        SECTEUR="2";
    }
    if (ui->Button_3->isChecked())
    {
        SECTEUR="3";
    }
    if (ui->Button_4->isChecked())
    {
        SECTEUR="4";
    }
    int QUANTITE = ui->Quantite->text().toInt();
    QString ETAT;

    if (ui->Mauvaise->isChecked())
    {
        ETAT="Mauvaise";
    }
    if (ui->Bonne->isChecked())
    {
        ETAT="Bonne";
    }
    QString CIN = ui->comboBox_cin->currentText();
    QString IDCATEGORIEPLANTE = ui->comboBox_categorie->currentText();
    QString IMG= ui->chemin->text();//LABEL CHEMIN
QString IDBP= ui->comboBox_IDBP->currentText();


    gestion_plante P(IDPLANTE,SECTEUR,QUANTITE,ETAT,IDCATEGORIEPLANTE,IMG,CIN,IDBP);
    bool test=tmppl.modifier_plante(P);
    if(test)
    {

        ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh

        ui->label_8->setText("Modifier plante");
        init();
        //sm.speak();//speek modifier
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
//Tri A-Z
void plante::on_radioButton_clicked()
{


  ui->afficher_plante->setModel(tmppl.afficher_SecteurCroissant());//refresh
    ui->label_8->setText("Tri A-Z");
}
//Tri Z-A
void plante::on_radioButton_2_clicked()
{
     ui->afficher_plante->setModel(tmppl.afficher_SecteurDecroissant());//refresh
    ui->label_8->setText("Tri Z-A");
}
//Tri Décroissant du Quantite
void plante::on_radioButton_3_clicked()
{



  ui->afficher_plante->setModel(tmppl.afficher_QuantiteDecroissant());//refresh
    ui->label_8->setText("Tri Décroissant du Quantite");
}
//Tri Croissant du Quantite
void plante::on_radioButton_5_clicked()
{
    ui->afficher_plante->setModel(tmppl.afficher_QuantiteCroissant());//refresh
    ui->label_8->setText("Tri Croissant du Quantite");
}
//statistique plante
void plante::on_pushButton_10_clicked()
{
    s=new Stat_plante(this);
    s->show();
}
//Tri Croissant par id
void plante::on_radioButton_4_clicked()
{


   ui->afficher_plante->setModel(tmppl.afficher_idCroissant());//refresh
    ui->label_8->setText("Tri Croissant par id ");
}
//Tri Decroissant par id
void plante::on_radioButton_6_clicked()
{
    ui->afficher_plante->setModel(tmppl.afficher_idDecroissant());//refresh
    ui->label_8->setText("Tri Decroissant par id ");
}
//creation pdf
int plante::on_pushButton_12_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\mahrousplusplus\\Historique PDF\\Liste des Plantes.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }




    QSqlQuery   query ;
    qDebug() << query.prepare("select sysdate from dual  ");//hethi date mta3 systeme d9i9et eli 3melet create pdf (clic 3al bouton )
    if ( query.exec() )
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(200,650,"  Plantes.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idP,Secteur,Etat,Quantite, idcp , url ,photo,cin,image;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from  PLANTES order by IDPLANTE ");

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);


    if ( qry.exec() )
    {

        while(qry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);
painter.drawText (0,10,"idP");
painter.drawText (40,10,"Secteur");
painter.drawText (90,10,"Etat");

painter.drawText (150,10,"Quantite");
painter.drawText (210,10,"idCP");
painter.drawText (260,10,"URL");
painter.drawText (520,10,"Photo");
painter.drawText (650,10,"CIN");
/*painter.drawText (590,10,"");
painter.drawText (650,10,"");*/
            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idP = qry.value(0).toString();
            painter.drawText(j*20,i, idP);
            j++;

            Secteur=qry.value(1).toString();
            painter.drawText(j*40,i, Secteur);
            j++;
            Etat=qry.value(2).toString();
            painter.drawText(j*50,i, Etat);
            j++;
            Quantite=qry.value(3).toString();
            painter.drawText(j*49,i,Quantite);
            j++;
           idcp=qry.value(4).toString();
            painter.drawText(j*55,i,idcp);
            j++;
            url=qry.value(5).toString();
            painter.drawText(j*56,i, url);
            j++;

            /*image=qry.value(7).toString();
            painter.drawText(j*54,i, image);*/

            QImage chemin(url);
            painter.drawPixmap(j*88,i,50,50,QPixmap::fromImage(QImage(chemin)));
            j++;
            cin=qry.value(6).toString();
            painter.drawText(j*90,i, cin);
            j++;
           /*idf=qry.value(8).toString();
                        painter.drawText(j*83,i, idf);*/

            i+=80;

            k++;



        }
    }

  ui->label_8->setText("Création pdf");

    painter.end();
}

void plante::on_pushButton_13_clicked()
{
    photo p;
     p.setchemin(ui->chemin->text());
     p.exec();
}
