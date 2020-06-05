#include "rh_fonctions_ops.h"
#include <QDebug>

rh_fonctions_ops::rh_fonctions_ops(){
    idFonction = "";
    nomFonction = "";
    salaire = -1;
    description = "";
}

rh_fonctions_ops::rh_fonctions_ops(QString idF, QString nF, int S, QString D){
    idFonction = idF;
    nomFonction = nF;
    salaire = S;
    description = D;
}

QString rh_fonctions_ops::getId(){
    return this->idFonction;
}

QString rh_fonctions_ops::getNom(){
    return this->nomFonction;
}

int rh_fonctions_ops::getSalaire(){
    return this->salaire;
}

QString rh_fonctions_ops::getDescription(){
    return this->description;
}

void rh_fonctions_ops::setId(QString id){
    this->idFonction = id;
}

void rh_fonctions_ops::setNom(QString nom){
    this->nomFonction = nom;
}

void rh_fonctions_ops::setSalaire(int flous){
    this->salaire = flous;
}

void rh_fonctions_ops::setDescription(QString desc){
    this->description = desc;
}

bool rh_fonctions_ops::ajouterFonction(){
    QSqlQuery query;
    query.prepare("insert into fonctions values (:idF , :nomF , :salaire , :desc);");
    query.bindValue(":idF",idFonction);
    query.bindValue(":nomF",nomFonction);
    query.bindValue(":salaire",salaire);
    query.bindValue(":desc",description);
    return query.exec();
}

QSqlQueryModel * rh_fonctions_ops::afficherFonctions(int mode){
    QSqlQueryModel * model = new QSqlQueryModel();

    switch(mode){
    case 0: model->setQuery("select nomFonction,idFonction from fonctions;"); break;
    case 1: model->setQuery("select * from fonctions;"); break;
    case 2: model->setQuery("select nomFonction,idFonction from fonctions where idfonction = '"+idFonction+"';"); break;
    }

    return model;
}

bool rh_fonctions_ops::modifFonction(){
    QSqlQuery query;
    query.prepare("update fonctions set nomFonction = :nomF , salaire = :salaire , descFonction = :desc where idfonction = :idF");
    query.bindValue(":idF",idFonction);
    query.bindValue(":nomF",nomFonction);
    query.bindValue(":salaire",salaire);
    query.bindValue(":desc",description);
    return query.exec();
}

bool rh_fonctions_ops::suppFonction(){
    QSqlQuery query;
    query.prepare("delete from fonctions where idfonction = :idF");
    query.bindValue(":idF",idFonction);
    return query.exec();
}
QSqlQueryModel * rh_fonctions_ops::afficher_idCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fonctions ORDER BY idfonction ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idFonction"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomFonction"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    return model;
}
QSqlQueryModel * rh_fonctions_ops::afficher_idDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fonctions ORDER BY idfonction desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idFonction"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomFonction"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    return model;
}
QSqlQueryModel * rh_fonctions_ops::afficher_SalaireCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fonctions ORDER BY salaire");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idFonction"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomFonction"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    return model;
}
QSqlQueryModel * rh_fonctions_ops::afficher_SalaireDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fonctions ORDER BY salaire desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idFonction"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomFonction"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    return model;
}
QSqlQueryModel * rh_fonctions_ops::afficher_NomCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fonctions ORDER BY nomFonction ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idFonction"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomFonction"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    return model;
}
QSqlQueryModel * rh_fonctions_ops::afficher_NomDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fonctions ORDER BY nomFonction desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idFonction"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomFonction"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    return model;
}
QSqlQueryModel *  rh_fonctions_ops::rechercher(QString q)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("select * from fonctions  where idfonction like '"+q+"' OR nomFonction like '"+q+"' OR salaire like '"+q+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPRODUCTIONPLANTE "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDCATEGORIEPLANTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRODUITPLANTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" PRIXPRODUITPLANTE"));

    return (model);
}
