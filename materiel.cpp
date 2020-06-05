#include "materiel.h"
#include "ui_materiel.h"
#include "gestion_materiel.h"
#include"categorie_materiel.h"
#include "image.h"
#include"statisqtique_materiel.h"

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
materiel::materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficher_materiel->setModel(tmpmat.afficher_materiel());

    ui->comboBox_categorie->setModel(tmpcat.afficher_Clist());
    ui->comboBox_idf->setModel(tmpf.afficher_Flist());
    ui->cx_idm->setEnabled(1);

    ui->count->setStyleSheet("QLabel{min-width: 20px; min-height: 20px;max-width:20px; max-height: 16px;border-radius: 8px;  border:1px solid black;background:red;}");

   ui->count->setNum(tmpmat.afficher_count());
   ui->pushButton_17->hide();
   ui->afficher_materiel_insu->hide();

}

materiel::~materiel()
{
    delete ui;
}
void materiel::init()
{
    ui->cx_idm->clear();
    // ui->cx_idc->clear();
    ui->photo->clear();
    ui->chemin->clear();
    ui->recherche->clear();
    ui->cx_marque->clear();
    //ui->cx_stock->clear();
   // ui->cx_prix->clear();
    ui->cx_desc->clear();
    ui->cx_nomM->clear();


}
//ajouter
void materiel::on_pushButton_clicked()
{


    QString IDMATERIEL = ui->cx_idm->text();
    QString NOMMATERIEL= ui->cx_nomM->text();
    QString MARQUEMATERIEL= ui->cx_marque->text();
    int PRIXMATERIEL = ui->prix->text().toInt();
    int STOCKMATERIEL = ui->stock->text().toInt();
    QString DESCMATERIEL= ui->cx_desc->text();
    QString IDCATEGORIE = ui->comboBox_categorie->currentText();
    QString IDFOURNISSUER = ui->comboBox_idf->currentText();
    QString IMAGE =ui->chemin->text();//LABEL CHEMIN

    gestion_materiel M(IDMATERIEL,NOMMATERIEL,MARQUEMATERIEL,PRIXMATERIEL,STOCKMATERIEL,DESCMATERIEL,IDCATEGORIE,IMAGE,IDFOURNISSUER);


    if(M.verif_id(M.get_idM())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                              QObject::tr(" Id doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }else if(M.verif_nom(M.get_nomM())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                              QObject::tr(" Nom doit contenir 20 caractéres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }else if(M.verif_nom(M.get_description())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                              QObject::tr(" Description doit contenir 100 caractéres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else{

        bool test=M.ajouter_materiel();
        if(test)
        {   ui->label_8->setText("Ajouter Matériel");
            QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueMateriel.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nMaterile  a été ajoutée sous : \nIdM:"+IDMATERIEL+"\nNomM: "+NOMMATERIEL+"\nMarqueM: "+MARQUEMATERIEL+"\nPrixM: "+PRIXMATERIEL+"\nStockM: "+STOCKMATERIEL+"\nDescriptionM: "+DESCMATERIEL+"\nIdC: "+IDCATEGORIE+"\nCheminImage: "+IMAGE+"\nIdF: "+IDFOURNISSUER ;
            cout << message2;
            ui->afficher_materiel->setModel(tmpmat.afficher_materiel());//refresh
             ui->count->setNum(tmpmat.afficher_count());
            init();

            sa.speak();//speek ajout

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                                  QObject::tr("Matériel existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}

//supprimer
void materiel::on_pushButton_2_clicked()
{
    QString idM = ui->cx_idm->text();

    bool test=tmpmat.supprimer_materiel(idM);
    if(test)
    {    ui->afficher_materiel->setModel(tmpmat.afficher_materiel());//refresh

        ui->label_8->setText("Supprimer Matériel ");
        init();
        //ss.speak();//speek supprimer
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Matériel"),
                              QObject::tr("verifier le id  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
//modifier
void materiel::on_pushButton_3_clicked()
{
    QString IDMATERIEL = ui->cx_idm->text();
    QString NOMMATERIEL= ui->cx_nomM->text();
    QString MARQUEMATERIEL= ui->cx_marque->text();
    int PRIXMATERIEL = ui->prix->text().toInt();
    int STOCKMATERIEL = ui->stock->text().toInt();
    QString DESCMATERIEL= ui->cx_desc->text();
    QString IDCATEGORIE = ui->comboBox_categorie->currentText();
    QString IDFOURNISSUER = ui->comboBox_idf->currentText();
    QString IMAGE= ui->chemin->text();//LABEL CHEMIN



    gestion_materiel M(IDMATERIEL,NOMMATERIEL,MARQUEMATERIEL,PRIXMATERIEL,STOCKMATERIEL,DESCMATERIEL,IDCATEGORIE,IMAGE,IDFOURNISSUER);
    bool test=tmpmat.modifier_materiel(M);
    if(test)
    {

        ui->afficher_materiel->setModel(tmpmat.afficher_materiel());//refresh

        ui->label_8->setText("Modifier Matériel");
        init();
        //sm.speak();//speek modifier
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Matériel"),
                              QObject::tr("Matériel non valide  !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

//ajouter photo materile
void materiel::on_pushButton_5_clicked()
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
//MODIFIER PHOTO
void materiel::on_pushButton_6_clicked()
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
//option Image
void materiel::on_pushButton_7_clicked()
{
    image p;
    p.setchemin(ui->chemin->text());
    p.exec();
}
//recherche
void materiel::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from MATERIEL where IDMATERIEL like '"+ui->recherche->text()+"' OR NOMMATERIEL like '"+ui->recherche->text()+"' OR MARQUEMATERIEL like '"+ui->recherche->text()+"' ");
    tmpmat.rechercher(q) ;
    q.exec();
    model->setQuery(q);
    ui->afficher_materiel->setModel(tmpmat.rechercher(q)) ;
    ui->label_8->setText("Chrecher");
}
//afficher la liste des materiaux
void materiel::on_pushButton_9_clicked()
{
    ui->afficher_materiel->setModel(tmpmat.afficher_materiel());//refresh
    ui->label_8->setText("Afficher la Liste des matériaux");
    init();
}
//Tri A-Z
void materiel::on_radioButton_clicked()
{

     ui->afficher_materiel->setModel(tmpmat.afficher_nomCroissant());//refresh
    ui->label_8->setText("Tri A-Z");
}
//Tri Z-A
void materiel::on_radioButton_2_clicked()
{
    ui->afficher_materiel->setModel(tmpmat.afficher_nomDecroissant());//refresh
    ui->label_8->setText("Tri Z-A");
}
//Tri Croissant du Prix
void materiel::on_radioButton_5_clicked()
{

 ui->afficher_materiel->setModel(tmpmat.afficher_PrixCroissant());//refresh
    ui->label_8->setText("Tri Croissant du Prix");
}
//Tri Décroissant du Prix
void materiel::on_radioButton_3_clicked()
{
   ui->afficher_materiel->setModel(tmpmat.afficher_PrixDecroissant());//refresh
    ui->label_8->setText("Tri Décroissant du Prix");
}
//Tri Croissant du Stock
void materiel::on_radioButton_6_clicked()
{


    ui->afficher_materiel->setModel(tmpmat.afficher_StockCroissant());//refresh
    ui->label_8->setText("Tri Croissant du Stock");
}
//Tri Décroissant du Stock
void materiel::on_radioButton_8_clicked()
{
    ui->afficher_materiel->setModel(tmpmat.afficher_StockDecroissant());//refresh
    ui->label_8->setText("Tri Décroissant du Stock");
}
//Trie Croissant d'IdMatériel
void materiel::on_radioButton_4_clicked()
{


    ui->afficher_materiel->setModel(tmpmat.afficher_idCroissant());//refresh
    ui->label_8->setText("Tri Croissant d'IdMatériel");
}
//Tri Décroissant d'IdMatériel
void materiel::on_radioButton_7_clicked()
{
    ui->afficher_materiel->setModel(tmpmat.afficher_idDecroissant());//refresh
    ui->label_8->setText("Tri Décroissant d'IdMatériel");
}
//statistique Materiel
void materiel::on_pushButton_10_clicked()
{
    s=new Statisqtique_materiel(this);
    s->show();
}


//cREATION Pdf
int materiel::on_pushButton_13_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\mahrousplusplus\\Historique PDF\\Historique Materiel.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
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
        painter.drawText(200,650,"  materiaux.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString id,nom,marque,prix ,stock , desc , idc , image ,idf;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from MATERIEL order by idmateriel ");

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
painter.drawText (0,10,"idM");
painter.drawText (40,10,"Nom");
painter.drawText (90,10,"Marque");

painter.drawText (150,10,"Prix");
painter.drawText (200,10,"Stock");
painter.drawText (260,10,"Desc");
painter.drawText (310,10,"idC");
painter.drawText (370,10,"URL");
painter.drawText (590,10,"Photo");
painter.drawText (650,10,"idF");
            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            id = qry.value(0).toString();
            painter.drawText(j*20,i, id);
            j++;

            nom=qry.value(1).toString();
            painter.drawText(j*40,i, nom);
            j++;
            marque=qry.value(2).toString();
            painter.drawText(j*50,i, marque);
            j++;
            prix=qry.value(3).toString();
            painter.drawText(j*49,i, prix);
            j++;
            stock=qry.value(4).toString();
            painter.drawText(j*51,i, stock);
            j++;
            desc=qry.value(5).toString();
            painter.drawText(j*52,i, desc);
            j++;
            idc=qry.value(6).toString();
            painter.drawText(j*53,i, idc);
            j++;
            image=qry.value(7).toString();
            painter.drawText(j*54,i, image);

            QImage chemin(image);
            painter.drawPixmap(j*80,i,50,50,QPixmap::fromImage(QImage(chemin)));
            j++;
           idf=qry.value(8).toString();
                        painter.drawText(j*83,i, idf);

            i+=80;

            k++;



        }
    }


 ui->label_8->setText("Creation PDF");
    painter.end();
}
//CAPTURE IMAGE
void materiel::on_pushButton_14_clicked()
{
    c=new capture(this);
    c->show();
}
//TABLE CLICKED
void materiel::on_afficher_materiel_activated(const QModelIndex &index)
{
    QString val=ui->afficher_materiel->model()->data(index).toString();
    QSqlQuery qry ;

   qry=tmpmat.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idm->setDisabled(1);
            ui->cx_idm->setText(qry.value(0).toString());
            ui->cx_nomM->setText(qry.value(1).toString());
            ui->cx_marque->setText(qry.value(2).toString());
            ui->prix->setValue(qry.value(3).toInt());
            ui->stock->setValue(qry.value(4).toInt());
            ui->cx_desc->setText(qry.value(5).toString());
            ui->comboBox_categorie->setCurrentText(qry.value(6).toString());
            ui->chemin->setText(qry.value(7).toString());
            QPixmap pix(ui->chemin->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            ui->comboBox_idf->setCurrentText(qry.value(8).toString());
             ui->label_8->setText("Matériel Selectionée");
        }
    }
}

void materiel::on_pushButton_4_clicked()
{
    ui->afficher_materiel_insu->show();
     ui->afficher_materiel_insu->setModel(tmpmat.afficher_IMlist());

ui->pushButton_17->show();
}

void materiel::on_pushButton_17_clicked()
{
    ui->afficher_materiel_insu->hide();
    ui->pushButton_17->hide();
}

void materiel::on_pushButton_18_clicked()
{
    ui->afficher_materiel->setModel(tmpmat.afficher_materiel());
}
