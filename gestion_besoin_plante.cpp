#include "gestion_besoin_plante.h"

gestion_besoin_plante::gestion_besoin_plante()
{

}
gestion_besoin_plante::gestion_besoin_plante(QString idB,int ep,QString np)
{
    this->idB=idB;
    this->ep=ep;
    this->np=np;
}

QString gestion_besoin_plante::get_idB(){return idB;}
int gestion_besoin_plante::get_ep(){return  ep;}
QString gestion_besoin_plante::get_np(){return  np;}

void gestion_besoin_plante::set_idB(QString idB){this->idB=idB;};
void gestion_besoin_plante::set_ep(int ep){this->ep=ep;};
void gestion_besoin_plante::set_np(QString np){this->np=np;};

bool gestion_besoin_plante::ajouter_besoin_plante()
{
    QSqlQuery query;

    query.prepare("INSERT INTO BESOINSPLANTES ( IDBESOINSPLANTE , EAUPLANTE , NUTRITIONPLANTE ) "
                        "VALUES ( :idB, :ep, :np ) ");

    query.bindValue(":idB",idB);
    query.bindValue(":ep",ep);
    query.bindValue(":np",np);

    return    query.exec();

}
QSqlQueryModel * gestion_besoin_plante::afficher_besoin_plante()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from BESOINSPLANTES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plante "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eau Plante"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nutrition Plante"));

    return model;
}
bool gestion_besoin_plante::supprimer_besoin_plante(QString idB )
{
QSqlQuery query;
QString res= QString(idB);
query.prepare("Delete from  BESOINSPLANTES where IDBESOINSPLANTE =:idB  ");
query.bindValue(":idB", res);
return    query.exec();
}
bool gestion_besoin_plante::modifier_besoin_plante(gestion_besoin_plante B)
{
    QSqlQuery query;

    query.prepare("UPDATE BESOINSPLANTES set  IDBESOINSPLANTE =:idB , EAUPLANTE=:ep ,  NUTRITIONPLANTE=:np  where IDBESOINSPLANTE =:idB");


    query.bindValue(":idB",B.get_idB());
    query.bindValue(":ep",B.get_ep());
    query.bindValue(":np",B.get_np());

    return    query.exec();
}



QSqlQueryModel *  gestion_besoin_plante::rechercher(QString q)
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from BESOINSPLANTES where IDBESOINSPLANTE like '"+q+"' OR NUTRITIONPLANTE like '"+q+"' OR EAUPLANTE like '"+q+"'  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plante "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eau Plante"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nutrition Plante"));

    return (model);
}
QSqlQuery  gestion_besoin_plante::tableclicked(QString a)
{

    QSqlQuery qry ;

    qry.prepare("Select * from  BESOINSPLANTES where IDBESOINSPLANTE='"+a+"' ");
    return qry;
}
QSqlQueryModel * gestion_besoin_plante::afficher_idCroissant()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BESOINSPLANTES  ORDER BY IDBESOINSPLANTE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plante "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eau Plante"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nutrition Plante"));



    return model;
}
QSqlQueryModel * gestion_besoin_plante::afficher_idDecroissant()
{ QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BESOINSPLANTES  ORDER BY IDBESOINSPLANTE desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plante "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eau Plante"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nutrition Plante"));



    return model;
}
QSqlQueryModel * gestion_besoin_plante::afficher_EauCroissant()
{ QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BESOINSPLANTES  ORDER BY EAUPLANTE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plante "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eau Plante"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nutrition Plante"));


    return model;
}
QSqlQueryModel * gestion_besoin_plante::afficher_EauDecroissant()
{ QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BESOINSPLANTES  ORDER BY EAUPLANTE desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plante "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eau Plante"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nutrition Plante"));


    return model;
}
QSqlQueryModel * gestion_besoin_plante::afficher_NutCroissant()
{ QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BESOINSPLANTES  ORDER BY  NUTRITIONPLANTE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plante "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eau Plante"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nutrition Plante"));

    return model;
}
QSqlQueryModel * gestion_besoin_plante::afficher_NutDecroissant()
{ QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BESOINSPLANTES  ORDER BY  NUTRITIONPLANTE desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plante "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eau Plante"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nutrition Plante"));

    return model;
}
QSqlQuery  gestion_besoin_plante::selectbesoinplante()
{

    QSqlQuery qry ;

  qry.prepare("select * from BESOINSPLANTES order by  IDBESOINSPLANTE ");
    return qry;
}
