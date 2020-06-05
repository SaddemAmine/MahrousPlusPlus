#include "rh_personnels.h"
#include "ui_rh_personnels.h"
#include "rh_personnels_ops.h"
#include "rh_fonctions_ops.h"
#include <QDebug>

rh_personnels::rh_personnels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rh_personnels)
{
    rh_personnels_ops p;
    rh_fonctions_ops f;
    ui->setupUi(this);
    ui->affichage->setModel(p.afficherPersonnels());
    //ui->comboBox->setModel(f.afficherFonctions(0));
}

rh_personnels::~rh_personnels()
{
    delete ui;
}

bool rh_personnels::controleDeSaisie(){
    bool result = true;
    bool number = true;
    ui->cx_cin->text().toInt(&number);

    if(ui->cx_nom->text() == ""){
        ui->remarque_nom->setText("*");
        ui->text_nom->setText("nom vide!");
        result = false;
    }
    else{
        ui->remarque_nom->setText("");
        ui->text_nom->setText("");
    }

    if(ui->cx_prenom->text() == ""){
        ui->remarque_prenom->setText("*");
        ui->text_prenom->setText("prenom vide!");
        result = false;
    }
    else{
        ui->remarque_prenom->setText("");
        ui->text_prenom->setText("");
    }

    if(ui->cx_cin->text() == ""){
        ui->remarque_cin->setText("*");
        ui->text_cin->setText("CIN vide!");
        result = false;
    }
    else
        if(!number || ui->cx_cin->text().length() != 8){
            ui->remarque_cin->setText("*");
            ui->text_cin->setText("Format incorrecte!");
            result = false;
        }
        else{
        ui->remarque_cin->setText("");
        ui->text_cin->setText("");
        }

    if(ui->cx_date->text() == ""){
        ui->remarque_date->setText("*");
        ui->text_date->setText("date vide!");
        result = false;
    }
    else{
        ui->remarque_date->setText("");
        ui->text_date->setText("");
    }

    if(ui->cx_adresse->text() == ""){
        ui->remarque_adresse->setText("*");
        ui->text_adresse->setText("adresse vide!");
        result = false;
    }
    else{
        ui->remarque_adresse->setText("");
        ui->text_adresse->setText("");
    }

    return result;
}

void rh_personnels::on_AjouterPersonnel_clicked()
{
    if(ui->cx_cin->isReadOnly()){
        ui->cx_cin->setStyleSheet("color:black;");
        ui->cx_cin->setReadOnly(false);
    }
    else{
        if(controleDeSaisie()){
            QAbstractItemModel * model = ui->comboBox->model();
            QString idF = model->data(model->index(ui->comboBox->currentIndex(),1)).toString();
            rh_personnels_ops pOps(ui->cx_cin->text(),ui->cx_nom->text(),ui->cx_prenom->text(),ui->cx_adresse->text(),ui->cx_date->text(),idF);
            pOps.ajouterPersonnel();
            ui->affichage->setModel(pOps.afficherPersonnels());
            ui->status->setText("Ajoutée!");
        }
    }
}

void rh_personnels::on_affichage_doubleClicked(const QModelIndex &index){
    QString val=ui->affichage->model()->data(index).toString().trimmed();

    rh_personnels_ops p;
    rh_fonctions_ops f;

    p.chargerPersonnel(val);
    ui->cx_cin->setText(p.getCin());
    ui->cx_nom->setText(p.getNom());
    ui->cx_prenom->setText(p.getPrenom());
    ui->cx_adresse->setText(p.getAdresse());
    ui->cx_date->setDate(QDate::fromString(p.getDateE().left(10),"yy/MM/dd"));

    f.setId(p.getIdFonction());
   // QAbstractItemModel * model = f.afficherFonctions(2);

   // ui->comboBox->setCurrentIndex(ui->comboBox->findText(model->data(model->index(0,0)).toString()));

    ui->cx_cin->setStyleSheet("color: grey;");
    ui->cx_cin->setReadOnly(true);
    ui->status->setText("Selectionnée!");
}

void rh_personnels::on_ModifierPeronnel_clicked(){
    if(!ui->cx_cin->isReadOnly()){
        ui->status->setText("Veuillez sélectionner d'abord...");
    }
    else{
        if(controleDeSaisie()){
            QAbstractItemModel * model = ui->comboBox->model();
            QString idF = model->data(model->index(ui->comboBox->currentIndex(),1)).toString();
            rh_personnels_ops pOps(ui->cx_cin->text(),ui->cx_nom->text(),ui->cx_prenom->text(),ui->cx_adresse->text(),ui->cx_date->text(),idF);
            pOps.modifPersonnel();
            ui->affichage->setModel(pOps.afficherPersonnels());
            ui->status->setText("Modifiée!");
        }
    }
}

void rh_personnels::on_SupprimerPersonnel_clicked(){
    if(!ui->cx_cin->isReadOnly()){
        ui->status->setText("Veuillez sélectionner d'abord...");
    }
    else{
        if(controleDeSaisie()){
            QAbstractItemModel * model = ui->comboBox->model();
            QString idF = model->data(model->index(ui->comboBox->currentIndex(),1)).toString();
            rh_personnels_ops pOps(ui->cx_cin->text(),ui->cx_nom->text(),ui->cx_prenom->text(),ui->cx_adresse->text(),ui->cx_date->text(),idF);
            pOps.suppPersonnel();
            ui->affichage->setModel(pOps.afficherPersonnels());
            ui->status->setText("Supprimée!");
        }
    }
}
