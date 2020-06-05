#include "animaux.h"
#include "ui_animaux.h"
#include "gestion_animaux.h"
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
#include "photo.h"
animaux::animaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animaux)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_animaux->setModel(tmppl.afficher_animaux());
    //ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
    ui->comboBox_idespece->setModel(tmpcat.afficher_Clist());
    ui->comboBox_cin->setModel(tmppl.afficher_CINlist());
    ui->comboBox_idba->setModel(tmppl.afficher_IDBAlist());
    ui->cx_ida->setEnabled(1);

}

animaux::~animaux()
{
    delete ui;
}

void animaux::init()
{
    ui->cx_ida->clear();
    // ui->cx_ide->clear();
    ui->photo->clear();
    ui->chemin->clear();
    //ui->recherche->clear();
    //ui->cx_sexe->clear();
    //ui->cx_etat->clear();
    ui->age->clear();


}

//ajouter
void animaux::on_pushButton_clicked()
{


    QString IDANIMAUX = ui->cx_ida->text();
    int AGEANIMAUX= ui->age->text().toInt();
    int IDESPECE = ui->comboBox_idespece->currentText().toInt();
    QString SEXEANIMAUX ;
    if (ui->femme->isChecked())
    {
        SEXEANIMAUX="femme";
    }
    if (ui->homme->isChecked())
    {
        SEXEANIMAUX="homme";
    }
    QString ETATANIMAUX;
    if (ui->Blesse->isChecked())
    {
        ETATANIMAUX="Blesse";
    }
    if (ui->Malade->isChecked())
    {
        ETATANIMAUX="Malade";
    }
    if (ui->Bonne->isChecked())
    {
        ETATANIMAUX="Bonne";
    }

    QString CIN=ui->comboBox_cin->currentText();
    QString IMAGEANIMAUX =ui->chemin->text();//LABEL CHEMIN
    QString IDBA=ui->comboBox_idba->currentText();

    gestion_animaux P(IDANIMAUX,IDESPECE,AGEANIMAUX,SEXEANIMAUX,ETATANIMAUX,IMAGEANIMAUX,CIN,IDBA);


    if(P.verif_id(P.get_idA())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter animaux"),
                              QObject::tr(" Id doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else{

        bool test=P.ajouter_animaux();
        if(test)
        {   ui->label_8->setText("Ajouter animaux");
            QFile file("A:\\integration\\mahrousplusplus\\Historique\\Historiqueanimaux.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\n L'historique des Personnels à ajouter :"+IDANIMAUX+" "+IDESPECE+" "+AGEANIMAUX+"  "+SEXEANIMAUX+" "+ETATANIMAUX+" "+IMAGEANIMAUX+" "+CIN+" "+IDBA ;
            cout << message2;
            ui->afficher_animaux->setModel(tmppl.afficher_animaux());//refresh
            sa.speak();//speek ajouter

            init();


        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter animaux"),
                                  QObject::tr("animaux existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}

//ajouter photo
void animaux::on_pushButton_5_clicked()
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
            ui->label_8->setText("Ajouter image");
        }

    }
}
//modifier image
void animaux::on_pushButton_4_clicked()
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
            ui->label_8->setText("Modifier image");
        }

    }
}

//affichage
void animaux::on_pushButton_9_clicked()
{
    ui->afficher_animaux->setModel(tmppl.afficher_animaux());//refresh
    ui->label_8->setText("Afficher Animaux");
}

//table clicked
void animaux::on_afficher_animaux_activated(const QModelIndex &index)
{
    QString val=ui->afficher_animaux->model()->data(index).toString();
    QSqlQuery qry ;
    qry=tmppl.tableclicked(val);

    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_ida->setDisabled(1);
            ui->cx_ida->setText(qry.value(0).toString());
            ui->comboBox_idespece->setCurrentText(qry.value(1).toString());
            ui->age->setValue(qry.value(2).toInt());
            //ui->cx_sexe->setText(qry.value(3).toString());
            if (qry.value(3).toString()=="femme")
            {
                ui->femme->setChecked(true);

            }
            if (qry.value(3).toString()=="homme")
            {
                ui->homme->setChecked(true);
            }
            //ui->cx_etat->setText(qry.value(4).toString());

            if (qry.value(4).toString()=="Blesse")
            {
                ui->Blesse->setChecked(true);

            }
            if (qry.value(4).toString()=="Malade")
            {
                ui->Malade->setChecked(true);
            }
            if (qry.value(4).toString()=="Bonne")
            {
                ui->Bonne->setChecked(true);
            }
            ui->chemin->setText(qry.value(5).toString());
            QPixmap pix(ui->chemin->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            ui->comboBox_cin->setCurrentText(qry.value(6).toString());
            ui->comboBox_idba->setCurrentText(qry.value(7).toString());


            ui->label_8->setText("Animale Selectionnée");
        }
    }
}

//supprimer
void animaux::on_pushButton_2_clicked()
{
    QString idA = ui->cx_ida->text();
    //on_pushButton_4_clicked();
    bool test=tmppl.supprimer_animaux(idA);
    if(test)
    {    ui->afficher_animaux->setModel(tmppl.afficher_animaux());//refresh
        ui->label_8->setText("Supprimer animaux ");
        //ss.speak();//speek supprimer
        init();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer animaux"),
                              QObject::tr("verifier le id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

//modifier
void animaux::on_pushButton_3_clicked()
{

    QString IDANIMAUX = ui->cx_ida->text();
    int IDESPECE = ui->comboBox_idespece->currentText().toInt();
    int AGEANIMAUX= ui->age->text().toInt();
    QString SEXEANIMAUX ;

            if (ui->femme->isChecked())
            {
                SEXEANIMAUX="femme";
            }
            if (ui->homme->isChecked())
            {
                SEXEANIMAUX="homme";
            }
   QString ETATANIMAUX;
    if (ui->Blesse->isChecked())
    {
        ETATANIMAUX="Blesse";
    }
    if (ui->Malade->isChecked())
    {
        ETATANIMAUX="Malade";
    }
    if (ui->Bonne->isChecked())
    {
        ETATANIMAUX="Bonne";
    }
    QString CIN = ui->comboBox_cin->currentText();
    QString IMAGEANIMAUX= ui->chemin->text();//LABEL CHEMIN
    QString IDBA = ui->comboBox_idba->currentText();


    gestion_animaux P(IDANIMAUX,IDESPECE,AGEANIMAUX,SEXEANIMAUX,ETATANIMAUX,IMAGEANIMAUX,CIN,IDBA);
    bool test=tmppl.modifier_animaux(P);
    if(test)
    {

        ui->afficher_animaux->setModel(tmppl.afficher_animaux());//refresh
        ui->label_8->setText("Modifier animaux");
        //sm.speak();//speek modifier
        init();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier animaux"),
                              QObject::tr("animaux non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
//recherche
void animaux::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from ANIMAUX where IDANIMAUX like '"+ui->recherche->text()+"' OR AGEANIMAUX like '"+ui->recherche->text()+"' OR ETATANIMAUX like '"+ui->recherche->text()+"' ");
    tmppl.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_animaux->setModel(tmppl.rechercher(q)) ;
    ui->label_8->setText("Chrecher");
}
//tier selon id animaux croissant
void animaux::on_radioButton_clicked()
{
    ui->afficher_animaux->setModel(tmppl.afficher_idCroissant());//refresh
    ui->label_8->setText("Tri ID");
}
//trier selon id animaux decroissant
void animaux::on_radioButton_2_clicked()
{
    ui->afficher_animaux->setModel(tmppl.afficher_idDecroissant());//refresh
    ui->label_8->setText("Tri ID DESC");
}
//trier age decroissant
void animaux::on_radioButton_3_clicked()
{
    ui->afficher_animaux->setModel(tmppl.afficher_AgeDecroissant());//refresh
    ui->label_8->setText("Tri Décroissant d'age");
}
//trier age croissant
void animaux::on_radioButton_5_clicked()
{
    ui->afficher_animaux->setModel(tmppl.afficher_AgeCroissant());//refresh
    ui->label_8->setText("Tri Croissant d'age");
}
//ouvrir stat animaux
void animaux::on_pushButton_10_clicked()
{
    s=new Stat_animaux(this);
    s->show();
    ui->label_8->setText("Statistique Animaux ");
}
//trier selon id Espece Croissant
void animaux::on_radioButton_4_clicked()
{
    ui->afficher_animaux->setModel(tmppl.afficher_IdECroissant());//refresh
    ui->label_8->setText("Tri Croissant par idE ");
}
//trier selon id Espece Decroissant
void animaux::on_radioButton_6_clicked()
{
    ui->afficher_animaux->setModel(tmppl.afficher_IdEDecroissant());//refresh
    ui->label_8->setText("Tri Decroissant par idE ");
}



//creation pdf
int animaux::on_pushButton_12_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\mahrousplusplus\\Historique PDF\\Liste des Animaux.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
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
        painter.drawText(200,650,"  Animaux.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idA,idE,Age,sexe, etat, url ,photo,cin,image;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from  ANIMAUX order by IDANIMAUX ");

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

                painter.drawText (0,10,"idA");
                painter.drawText (40,10,"idE");
                painter.drawText (90,10,"Age");

                painter.drawText (150,10,"sexe");
                painter.drawText (210,10,"etat");
                painter.drawText (260,10,"url");
                painter.drawText (520,10,"photo");
                painter.drawText (650,10,"CIN");
                /*painter.drawText (590,10,"");
painter.drawText (650,10,"");*/
            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idA = qry.value(0).toString();
            painter.drawText(j*20,i, idA);
            j++;

            idE=qry.value(1).toString();
            painter.drawText(j*40,i, idE);
            j++;
            Age=qry.value(2).toString();
            painter.drawText(j*50,i,Age);
            j++;
            sexe=qry.value(3).toString();
            painter.drawText(j*49,i,sexe);
            j++;
            etat=qry.value(4).toString();
            painter.drawText(j*55,i,etat);
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
    ui->label_8->setText("Creation PDF");


    painter.end();
}

void animaux::on_pushButton_13_clicked()
{

   photo p;
    p.setchemin(ui->chemin->text());
    p.exec();
}
