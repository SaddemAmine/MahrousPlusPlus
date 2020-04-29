#include "gestion_categorie_plante.h"

gestion_categorie_plante::gestion_categorie_plante()
{

}

gestion_categorie_plante::gestion_categorie_plante(QString idC,QString nomC)
{
    this->idC=idC;
    this->nomC=nomC;
}

QString gestion_categorie_plante::get_idC(){return idC;}
QString gestion_categorie_plante::get_nomC(){return  nomC;}

void gestion_categorie_plante::set_idC(QString idC){this->idC=idC;};
void gestion_categorie_plante::set_nomC(QString nomC){this->nomC=nomC;};

bool gestion_categorie_plante::ajouter_Categorie()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CATEGORIESPLANTES ( IDCATEGORIEPLANTE , NOMCATEGORIEPLANTE ) "
                        "VALUES ( :idC, :nomC ) ");

    query.bindValue(":idC",idC);
    query.bindValue(":nomC",nomC);

    return    query.exec();

}
QSqlQueryModel * gestion_categorie_plante::afficher_Categorie()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CATEGORIESPLANTES ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Catégorie "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Catégorie"));

    return model;
}
bool gestion_categorie_plante::supprimer_Categorie(QString idC )
{
QSqlQuery query;
QString res= QString(idC);
query.prepare("Delete from  CATEGORIESPLANTES where IDCATEGORIEPLANTE =:idC  ");
query.bindValue(":idC", res);
return    query.exec();
}
bool gestion_categorie_plante::modifier_Categorie(gestion_categorie_plante C)
{
    QSqlQuery query;

    query.prepare("UPDATE CATEGORIESPLANTES set IDCATEGORIEPLANTE = :idC , NOMCATEGORIEPLANTE = :nomC where IDCATEGORIEPLANTE = :idC ");

    query.bindValue(":idC",C.get_idC());
    query.bindValue(":nomC",C.get_nomC());

    return    query.exec();
}

QSqlQueryModel * gestion_categorie_plante::afficher_Clist()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select IDCATEGORIEPLANTE from CATEGORIESPLANTES ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Catégorie "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Catégorie"));
    return model;
}


bool gestion_categorie_plante::verif_idC(QString idC)
{
   bool test=true;
   int i;
   if(idC.length()==0){
      test=false;
      return  test;
   }else{
       for(i=0;i<idC.length();i++){
           if(!((idC[i]>='0')&&(idC[i]<='9'))){
               test=false;
               return  test;
       }
       }
   }
return test;}
bool gestion_categorie_plante::verif_vide(QString a)
{

    bool test=true;

    if(a.length()==0){
       test=false;

    }
    return  test;
}
bool gestion_categorie_plante::verif_Nom(QString nomC)
{
    bool test=true;
    int i;
    if(nomC.length()==0){
       test=false;
       return  test;
    }else{
        for(i=0;i<nomC.length();i++){
            if(!((nomC[i]>='a')&&(nomC[i]<='z'))){
                test=false;
                return  test;
        }
        }
}
    return test;
}
QSqlQueryModel *  gestion_categorie_plante::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}

