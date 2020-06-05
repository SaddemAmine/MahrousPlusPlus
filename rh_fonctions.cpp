#include "rh_fonctions.h"
#include "ui_rh_fonctions.h"
#include <QDebug>

rh_fonctions::rh_fonctions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rh_fonctions)
{
    rh_fonctions_ops rhf;
    ui->setupUi(this);
   //ui->affichage->setModel(rhf.afficherFonctions(1));
}

rh_fonctions::~rh_fonctions(){
    delete ui;
}

bool rh_fonctions::controleDeSaisie(){
    bool result = true;
    bool number = true;
    ui->cx_salaire->text().toInt(&number);

    qDebug() << ui->cx_idFonction->text() << ui->cx_nomFonction->text() << ui->cx_salaire->text() << ui->cx_description->text() << number << endl;

    if(ui->cx_idFonction->text() == ""){
        ui->remarque_id->setText("*");
        ui->text_id->setText("id vide!");
        result = false;
    }
    else{
        ui->remarque_id->setText("");
        ui->text_id->setText("");
    }

    if(ui->cx_nomFonction->text() == ""){
        ui->remarque_nom->setText("*");
        ui->text_nom->setText("nom vide!");
        result = false;
    }
    else{
        ui->remarque_nom->setText("");
        ui->text_nom->setText("");
    }

    if(ui->cx_salaire->text() == ""){
        ui->remarque_salaire->setText("*");
        ui->text_salaire->setText("salaire vide!");
        result = false;
    }
    else
        if(!number){
            ui->remarque_salaire->setText("*");
            ui->text_salaire->setText("salaire non numérique!");
            result = false;
        }
        else{
        ui->remarque_salaire->setText("");
        ui->text_salaire->setText("");
        }

    if(ui->cx_description->text() == ""){
        ui->remarque_desc->setText("*");
        ui->text_desc->setText("description vide!");
        result = false;
    }
    else{
        ui->remarque_desc->setText("");
        ui->text_desc->setText("");
    }

    return result;
}

void rh_fonctions::on_AjouterCategorieMateriel_clicked(){
    if(ui->cx_idFonction->isReadOnly()){
        ui->cx_idFonction->setStyleSheet("color:black;");
        ui->cx_idFonction->setReadOnly(false);
    }
    else{
        if(controleDeSaisie()){
            rh_fonctions_ops fOps(ui->cx_idFonction->text(),ui->cx_nomFonction->text(),ui->cx_salaire->text().toInt(),ui->cx_description->text());
            fOps.ajouterFonction();
            //ui->affichage->setModel(fOps.afficherFonctions(1));
            ui->status->setText("Ajoutée!");
            //sa.speak();
        }
    }
}


void rh_fonctions::on_affichage_doubleClicked(const QModelIndex &index){
    QString val=ui->affichage->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from fonctions where idFonction = '"+val+"';");
    if (query.exec())
    {
        while (query.next())
        {

            ui->cx_idFonction->setStyleSheet("color: grey;");
            ui->cx_idFonction->setReadOnly(true);
            ui->cx_idFonction->setText(query.value(0).toString());
            ui->cx_nomFonction->setText(query.value(1).toString());
            ui->cx_salaire->setText(query.value(2).toString());
            ui->cx_description->setText(query.value(3).toString());
        }
    }
    ui->status->setText("Selectionnée!");
}

void rh_fonctions::on_ModifierCategorieMaeriel_clicked()
{
    if(!ui->cx_idFonction->isReadOnly()){
        ui->status->setText("Veuillez sélectionner d'abord...");
    }
    else{
        if(controleDeSaisie()){
            rh_fonctions_ops fOps(ui->cx_idFonction->text(),ui->cx_nomFonction->text(),ui->cx_salaire->text().toInt(),ui->cx_description->text());
            fOps.modifFonction();
            //ui->affichage->setModel(fOps.afficherFonctions(1));
            ui->status->setText("Modifiée!");
            //sm.speak();
        }
    }
}

void rh_fonctions::on_SupprimerCategorieMateriel_clicked(){
    if(!ui->cx_idFonction->isReadOnly()){
        ui->status->setText("Veuillez sélectionner d'abord...");
    }
    else{
        if(controleDeSaisie()){
            rh_fonctions_ops fOps(ui->cx_idFonction->text(),ui->cx_nomFonction->text(),ui->cx_salaire->text().toInt(),ui->cx_description->text());
            fOps.suppFonction();
           // ui->affichage->setModel(fOps.afficherFonctions(1));
            ui->status->setText("Supprimée!");
            //ss.speak();
        }
    }
}
