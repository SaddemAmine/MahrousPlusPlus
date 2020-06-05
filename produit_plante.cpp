#include "produit_plante.h"
#include "ui_produit_plante.h"
#include "gestion_produit_plante.h"
#include <QMessageBox>
#include<QFile>
#include<QTextStream>
produit_plante::produit_plante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produit_plante)
{
    ui->setupUi(this);
    ui->comboBox_CP->setModel(tmppp->afficher_pplist());
}

produit_plante::~produit_plante()
{
    delete ui;
}

void produit_plante::on_pushButton_clicked()
{
    int IDPRODUCTIONPLANTE   = ui->cx_pp->text().toInt();
    int  IDCATEGORIEPLANTE = ui->comboBox_CP->currentIndex();

    QString PRODUITPLANTE= ui->cx_produitp->text();
    int PRIXPRODUITPLANTE = ui->cx_prix->text().toInt();

    gestion_produit_plante PP(IDPRODUCTIONPLANTE,IDCATEGORIEPLANTE,PRODUITPLANTE,PRIXPRODUITPLANTE);



    if(PP.verif_id(PP.get_idPP())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                              QObject::tr(" Id doit contenir >0 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else{

        bool test=PP.ajouter_produit_plante();
        if(test)
        {   //ui->label_8->setText("Ajouter Matériel");
            /* QFile file("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueProduitPlantes.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QString res1= QString::number(IDPRODUCTIONPLANTE);
            QString res2= QString::number(IDCATEGORIEPLANTE);
               QString res3= QString::number(PRIXPRODUITPLANTE);

            QTextStream cout(&file);
            QString message2="\n L'historique des Personnels à ajouter :"+IDPRODUCTIONPLANTE+" "+IDCATEGORIEPLANTE+" "+PRODUITPLANTE+" "+PRIXPRODUITPLANTE ;
            cout << message2;
            //ui->afficher_materiel->setModel(tmpmat.afficher_materiel());//refresh
            //ui->comboBox_supp->setModel(tmpmat.afficher_Mlist());
           // init();
            //ui->comboBox_mail->setModel(tmppers.getMailModel());
           // sa.speak();//speek ajout*/

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                                  QObject::tr("Matériel existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}
