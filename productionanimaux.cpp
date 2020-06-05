#include "productionanimaux.h"
#include "ui_productionanimaux.h"
#include "gestion_productionanimaux.h"
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

productionanimaux::productionanimaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::productionanimaux)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_productionanimaux->setModel(tmppl.afficher_productionanimaux());
    //ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
    ui->comboBox_idespece->setModel(tmpcat.afficher_Clist());
    ui->cx_idp->setEnabled(1);

}

productionanimaux::~productionanimaux()
{
    delete ui;
}

void productionanimaux::init()
{
    ui->cx_idp->clear();
   // ui->cx_ide->clear();
    ui->photo->clear();
    ui->chemin->clear();
    //ui->recherche->clear();
    ui->cx_ppa->clear();
    ui->cx_prix->clear();


}

//ajouter
void productionanimaux::on_pushButton_clicked()
{


    int IDPRODUCTIONANIMAUX = ui->cx_idp->text().toInt();
    int IDESPECE = ui->comboBox_idespece->currentText().toInt();
    QString PRODUITPRODUCTIONANIMAUX = ui->cx_ppa->text();
    int PRIXPRODUCTIONANIMAUX= ui->cx_prix->text().toInt();
    QString IMAGEPRODUCTIONANIMAUX =ui->chemin->text();//LABEL CHEMIN
   /* QAbstractItemModel * a = ui->comboBox_idespece->model();
    QString IDCATEGORIE= a->data(a->index(ui->comboBox_idespece->currentIndex(),1)).toString();*/
    gestion_productionanimaux P(IDPRODUCTIONANIMAUX,IDESPECE,PRODUITPRODUCTIONANIMAUX,PRIXPRODUCTIONANIMAUX,IMAGEPRODUCTIONANIMAUX);


    if((P.get_idP())==0){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter productionanimaux"),
                              QObject::tr(" Id doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }/*else if(P.verif_age(P.get_age())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter productionanimaux"),
                              QObject::tr(" age doit contenir 5 caractéres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }*/
    else{

        bool test=P.ajouter_productionanimaux();
        if(test)
        {   ui->label_8->setText("Ajouter productionanimaux");
           QFile file("A:\\integration\\mahrousplusplus\\Historique\\Historiqueproductionanimaux.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
           QTextStream cout(&file);
            QString res1= QString::number(IDPRODUCTIONANIMAUX);
            QString message2="\n L'historique  à ajouter :" +res1+" "+IDESPECE+" "+PRODUITPRODUCTIONANIMAUX+"  "+PRIXPRODUCTIONANIMAUX+" "+IMAGEPRODUCTIONANIMAUX ;
            cout << message2;
            ui->afficher_productionanimaux->setModel(tmppl.afficher_productionanimaux());//refresh
            sa.speak();//speek ajouter
            //ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
            init();
            //ui->comboBox_mail->setModel(tmppers.getMailModel());

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter productionanimaux"),
                                  QObject::tr("productionanimaux existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}

//ajouter photo
void productionanimaux::on_pushButton_5_clicked()
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
//modifier image
void productionanimaux::on_pushButton_4_clicked()
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
void productionanimaux::on_pushButton_9_clicked()
{
    ui->afficher_productionanimaux->setModel(tmppl.afficher_productionanimaux());//refresh
  //  ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
}


void productionanimaux::on_afficher_productionanimaux_activated(const QModelIndex &index)
{
    QString val=ui->afficher_productionanimaux->model()->data(index).toString();
    QSqlQuery qry ;

    qry.prepare("Select * from PRODUCTIONANIMAUX where IDPRODUCTIONANIMAUX='"+val+"' ");

    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idp->setDisabled(1);
            ui->cx_idp->setText(qry.value(0).toString());
             ui->comboBox_idespece->setCurrentText(qry.value(1).toString());
            ui->cx_ppa->setText(qry.value(2).toString());
            ui->cx_prix->setText(qry.value(3).toString());
            ui->chemin->setText(qry.value(4).toString());
            QPixmap pix(ui->chemin->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
}

//supprimer
void productionanimaux::on_pushButton_2_clicked()
{
    int idP = ui->cx_idp->text().toInt();
            //on_pushButton_4_clicked();
    bool test=tmppl.supprimer_productionanimaux(idP);
    if(test)
    {    ui->afficher_productionanimaux->setModel(tmppl.afficher_productionanimaux());//refresh
       // ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
        ui->label_8->setText("Supprimer productionanimaux ");
        //ss.speak();//speek supprimer
        init();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer productionanimaux"),
                              QObject::tr("verifier le id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

//modifier
void productionanimaux::on_pushButton_3_clicked()
{
    int IDPRODUCTIONANIMAUX = ui->cx_idp->text().toInt();
    int IDESPECE = ui->comboBox_idespece->currentText().toInt();
    QString PRODUITPRODUCTIONANIMAUX = ui->cx_ppa->text();
    int PRIXPRODUCTIONANIMAUX= ui->cx_prix->text().toInt();
    QString IMAGEPRODUCTIONANIMAUX= ui->chemin->text();//LABEL CHEMIN



    gestion_productionanimaux P(IDPRODUCTIONANIMAUX,IDESPECE,PRODUITPRODUCTIONANIMAUX,PRIXPRODUCTIONANIMAUX,IMAGEPRODUCTIONANIMAUX);
    bool test=tmppl.modifier_productionanimaux(P);
    if(test)
    {

        ui->afficher_productionanimaux->setModel(tmppl.afficher_productionanimaux());//refresh
        //ui->comboBox_supp->setModel(tmppl.afficher_Mlist());
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
void productionanimaux::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from PRODUCTIONANIMAUX where IDPRODUCTIONANIMAUX like '"+ui->recherche->text()+"' OR PRODUITPRODUCTIONANIMAUX like '"+ui->recherche->text()+"' OR PRIXPRODUCTIONANIMAUX like '"+ui->recherche->text()+"' ");
    tmppl.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_productionanimaux->setModel(tmppl.rechercher(q)) ;
    ui->label_8->setText("Chrecher");
}

void productionanimaux::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUCTIONANIMAUX ORDER BY IDPRODUCTIONANIMAUX ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEsp"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Image"));


    ui->afficher_productionanimaux->setModel(model) ;
    ui->label_8->setText("Tri ID");
}

void productionanimaux::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUCTIONANIMAUX ORDER BY IDPRODUCTIONANIMAUX DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEsp"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Image"));



    ui->afficher_productionanimaux->setModel(model) ;
    ui->label_8->setText("Tri ID DESC");
}

void productionanimaux::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUCTIONANIMAUX ORDER BY PRODUITPRODUCTIONANIMAUX desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEsp"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Image"));


    ui->afficher_productionanimaux->setModel(model) ;
    ui->label_8->setText("Tri Décroissant d'age");
}

void productionanimaux::on_radioButton_5_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUCTIONANIMAUX ORDER BY PRODUITPRODUCTIONANIMAUX  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEsp"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Image"));


    ui->afficher_productionanimaux->setModel(model) ;
    ui->label_8->setText("Tri Croissant d'age");
}

void productionanimaux::on_pushButton_10_clicked()
{
    s=new Stat_productionanimaux(this);
    s->show();
}

















int productionanimaux::on_pushButton_12_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\mahrousplusplus\\Historique PDF\\Liste desproduction Animaux.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
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
        painter.drawText(200,650,"  productionAnimaux.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idP,idE,ppa,prix, url ,photo,image;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from  PRODUCTIONANIMAUX order by IDPRODUCTIONANIMAUX ");

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
painter.drawText (40,10,"idE");
painter.drawText (90,10,"ppa");

painter.drawText (150,10,"prix");
painter.drawText (260,10,"url");
painter.drawText (520,10,"photo");
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

            idE=qry.value(1).toString();
            painter.drawText(j*40,i, idE);
            j++;
           ppa=qry.value(2).toString();
            painter.drawText(j*50,i,ppa);
            j++;
            prix=qry.value(3).toString();
            painter.drawText(j*49,i,prix);
            j++;
            url=qry.value(4).toString();
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



    painter.end();
}
