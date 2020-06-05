#include "besoinanimaux.h"
#include "ui_besoinanimaux.h"
#include "gestion_besoinanimaux.h"
#include"especeanimal.h"
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

besoinanimaux::besoinanimaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::besoinanimaux)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_besoinanimaux->setModel(tmppl.afficher_besoinanimaux());

    ui->cx_idb->setEnabled(1);

}

besoinanimaux::~besoinanimaux()
{
    delete ui;
}

void besoinanimaux::init()
{
    ui->cx_idb->clear();
    ui->cx_eau->clear();
    ui->photo->clear();
    ui->chemin->clear();
    //ui->recherche->clear();
    ui->cx_nutrition->clear();
    ui->cx_abri->clear();
    ui->cx_vaco->clear();


}

//ajouter besoin animaux
void besoinanimaux::on_pushButton_clicked()
{


    int IDBESOINANIMAUX = ui->cx_idb->text().toInt();
    int EAUANIMAUX= ui->cx_eau->text().toInt();
    QString NUTRITIONANIMAUX = ui->cx_nutrition->text();
    QString ABRIANIMAUX= ui->cx_abri->text();
    QString VACOANIMAUX=ui->cx_vaco->text();
    QString IMAGEANIMAUX =ui->chemin->text();//LABEL CHEMIN

    gestion_besoinanimaux P(IDBESOINANIMAUX,EAUANIMAUX,NUTRITIONANIMAUX,ABRIANIMAUX,VACOANIMAUX,IMAGEANIMAUX);


    if(P.verif_id(P.get_idB())==0){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter animaux"),
                              QObject::tr(" Id doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else{

        bool test=P.ajouter_besoinanimaux();
        if(test)
        {   ui->label_8->setText("Ajouter Besoin animaux");
            QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueBesoinAnimaux.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QString res1= QString::number(IDBESOINANIMAUX);
            QString res2= QString::number(EAUANIMAUX);
            QTextStream cout(&file);
            QString message2="\nBesoin Animala été ajouter sous  :"+res1+" "+res2+" "+NUTRITIONANIMAUX+" "+ABRIANIMAUX+" "+VACOANIMAUX+" "+IMAGEANIMAUX ;
            cout << message2;
            ui->afficher_besoinanimaux->setModel(tmppl.afficher_besoinanimaux());//refresh

            init();

            sa.speak();//speek ajout

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter animaux"),
                                  QObject::tr("animaux existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}

//ajouter photo
void besoinanimaux::on_pushButton_5_clicked()
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
            ui->label_8->setText("Ajouter Image");
        }

    }
}
//modifier image
void besoinanimaux::on_pushButton_4_clicked()
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
            ui->label_8->setText("Modifier Image");
        }

    }
}

//affichage
void besoinanimaux::on_pushButton_9_clicked()
{
    ui->afficher_besoinanimaux->setModel(tmppl.afficher_besoinanimaux());//refresh
    ui->label_8->setText("Afficher Besoin Animaux");
}

//table clicked
void besoinanimaux::on_afficher_besoinanimaux_activated(const QModelIndex &index)
{
    QString val=ui->afficher_besoinanimaux->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tmppl.tableclicked(val);

    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idb->setDisabled(1);
            ui->cx_idb->setText(qry.value(0).toString());
            ui->cx_eau->setText(qry.value(1).toString());
            ui->cx_nutrition->setText(qry.value(2).toString());
            ui->cx_abri->setText(qry.value(3).toString());
            ui->cx_vaco->setText(qry.value(4).toString());
            ui->chemin->setText(qry.value(5).toString());
            QPixmap pix(ui->chemin->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            ui->label_8->setText("Besoin Animal Selectionée");
        }
    }
}

//supprimer
void besoinanimaux::on_pushButton_2_clicked()
{
    int idB = ui->cx_idb->text().toInt();

    bool test=tmppl.supprimer_besoinanimaux(idB);
    if(test)
    {    ui->afficher_besoinanimaux->setModel(tmppl.afficher_besoinanimaux());//refresh

        ui->label_8->setText("Supprimer Besoin Animal");
        init();
        //ss.speak();//speek supprimer
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer animaux"),
                              QObject::tr("verifier le id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

//modifier
void besoinanimaux::on_pushButton_3_clicked()
{
    int IDBESOINANIMAUX = ui->cx_idb->text().toInt();
    int EAUANIMAUX= ui->cx_eau->text().toInt();
    QString NUTRITIONANIMAUX = ui->cx_nutrition->text();
    QString ABRIANIMAUX= ui->cx_abri->text();
    QString VACOANIMAUX = ui->cx_vaco->text();
    QString IMAGEANIMAUX= ui->chemin->text();//LABEL CHEMIN



    gestion_besoinanimaux P(IDBESOINANIMAUX,EAUANIMAUX,NUTRITIONANIMAUX,ABRIANIMAUX,VACOANIMAUX,IMAGEANIMAUX);
    bool test=tmppl.modifier_besoinanimaux(P);
    if(test)
    {

        ui->afficher_besoinanimaux->setModel(tmppl.afficher_besoinanimaux());//refresh

        ui->label_8->setText("Modifier Besoin Animal");
        init();
        //sm.speak();//speel modifier
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier animaux"),
                              QObject::tr("animaux non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
//recherche
void besoinanimaux::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from BESOINSANIMAUX where IDBESOINANIMAUX like '"+ui->recherche->text()+"' OR EAUANIMAUX like '"+ui->recherche->text()+"' OR NUTRITIONANIMAUX like '"+ui->recherche->text()+"' ");
    tmppl.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_besoinanimaux->setModel(tmppl.rechercher(q)) ;
    ui->label_8->setText("Chrecher");
}
//Tri Croissant IDBesoin
void besoinanimaux::on_radioButton_clicked()
{
    ui->afficher_besoinanimaux->setModel(tmppl.afficher_idCroissant());//refresh

    ui->label_8->setText("Tri Croissant IDBesoin");
}
//Tri Decroisant IDBesoin
void besoinanimaux::on_radioButton_2_clicked()
{



 ui->afficher_besoinanimaux->setModel(tmppl.afficher_idDecroissant());//refresh

    ui->label_8->setText("Tri Decroisant IDBesoin");
}
//Tri Décroissant de Qauntite d'eau
void besoinanimaux::on_radioButton_3_clicked()
{



   ui->afficher_besoinanimaux->setModel(tmppl.afficher_EauDecroissant());//refresh
    ui->label_8->setText("Tri Décroissant de Qauntite d'eau");
}
//Tri Croissant de quantite d'eau
void besoinanimaux::on_radioButton_5_clicked()
{
   ui->afficher_besoinanimaux->setModel(tmppl.afficher_EauCroissant());//refresh
    ui->label_8->setText("Tri Croissant de quantite d'eau");
}
//stat besoin animaux
void besoinanimaux::on_pushButton_10_clicked()
{
    s=new stat_besoinanimaux(this);
    s->show();
}
//Tri A-Z Nutrition Animaux
void besoinanimaux::on_radioButton_4_clicked()
{

  ui->afficher_besoinanimaux->setModel(tmppl.afficher_NutCroissant());
    ui->label_8->setText("Tri A-Z Nutrition Animaux ");
}
//Tri Z-A par Nutrition Animaux
void besoinanimaux::on_radioButton_6_clicked()
{
    ui->afficher_besoinanimaux->setModel(tmppl.afficher_NutDecroissant());
    ui->label_8->setText("Tri Z-A par Nutrition Animaux ");
}
//creation pdf
int besoinanimaux::on_pushButton_12_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\mahrousplusplus\\Historique PDF\\Liste des Besoin Animaux.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
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
        painter.drawText(180,650,"Besoin Animaux.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idB,eau,nuttrition,ABRI, VAC, url ,photo,image;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from  BESOINSANIMAUX  order by IDBESOINANIMAUX ");

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

                painter.drawText (0,10,"idB");
                painter.drawText (40,10,"eau");
                painter.drawText (90,10,"nuttrition");

                painter.drawText (150,10,"ABRI");
                painter.drawText (210,10,"VAC");
                painter.drawText (260,10,"url");
                painter.drawText (520,10,"photo");
                //painter.drawText (650,10,"CIN");
                /*painter.drawText (590,10,"");
painter.drawText (650,10,"");*/
            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idB = qry.value(0).toString();
            painter.drawText(j*20,i, idB);
            j++;

            eau=qry.value(1).toString();
            painter.drawText(j*40,i, eau);
            j++;
            nuttrition=qry.value(2).toString();
            painter.drawText(j*50,i,nuttrition);
            j++;
            ABRI=qry.value(3).toString();
            painter.drawText(j*49,i,ABRI);
            j++;
            VAC=qry.value(4).toString();
            painter.drawText(j*55,i,VAC);
            j++;
            url=qry.value(5).toString();
            painter.drawText(j*56,i, url);
            j++;

            /*image=qry.value(7).toString();
            painter.drawText(j*54,i, image);*/

            QImage chemin(url);
            painter.drawPixmap(j*88,i,50,50,QPixmap::fromImage(QImage(chemin)));
            j++;

            /*idf=qry.value(8).toString();
                        painter.drawText(j*83,i, idf);*/

            i+=80;

            k++;



        }
    }

 ui->label_8->setText("Creation PDF");

    painter.end();
}
