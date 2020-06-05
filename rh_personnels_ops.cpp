#include "rh_personnels_ops.h"
#include <QDebug>

rh_personnels_ops::rh_personnels_ops(){
    cin = "";
    nom = "";
    prenom = "";
    adresse = "";
    dateE = "";
    idFonction = "";
}

rh_personnels_ops::rh_personnels_ops(QString cin, QString nom, QString prenom, QString adresse, QString dateE, QString idFonction){
    this->cin = cin;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->dateE = dateE;
    this->idFonction = idFonction;
}

bool rh_personnels_ops::ajouterPersonnel(){
    QSqlQuery query;
    query.prepare("insert into personnels values (:cin , :nom , :prenom , :adresse , :dateE , :idFonction);");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":dateE",dateE);
    query.bindValue(":idFonction",idFonction);
    return query.exec();
}

QSqlQueryModel * rh_personnels_ops::afficherPersonnels(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from personnels;");
    return model;
}

void rh_personnels_ops::chargerPersonnel(QString val){
    QSqlQuery query;
    query.prepare("select * from personnels where cin = '"+val+"';");
    if (query.exec())
    {
        while (query.next())
        {
            cin = query.value(0).toString();
            nom = query.value(1).toString();
            prenom = query.value(2).toString();
            adresse = query.value(3).toString();
            dateE = query.value(4).toString();
            idFonction = query.value(5).toString();
        }
    }
    //qDebug() << idFonction << " " << cin << " " <<val;
}

bool rh_personnels_ops::modifPersonnel(){
    QSqlQuery query;
    query.prepare("update personnels set nompersonnel = :nom , prenompersonnel = :prenom , adresse = :adresse , dateembauche = :dateE , idfonction = :idFonction where cin = :cin");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":dateE",dateE);
    query.bindValue(":idFonction",idFonction);
    return query.exec();
}

bool rh_personnels_ops::suppPersonnel(){
    QSqlQuery query;
    query.prepare("delete from personnels where cin = :cin");
    query.bindValue(":cin",cin);
    return query.exec();
}
