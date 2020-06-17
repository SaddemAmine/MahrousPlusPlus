#include "gestion_especeanimal.h"

gestion_especeanimal::gestion_especeanimal()
{

}

gestion_especeanimal::gestion_especeanimal(QString idC,QString nomC)
{
    this->idC=idC;
    this->nomC=nomC;
}

QString gestion_especeanimal::get_idC(){return idC;}
QString gestion_especeanimal::get_nomC(){return  nomC;}

void gestion_especeanimal::set_idC(QString idC){this->idC=idC;};
void gestion_especeanimal::set_nomC(QString nomC){this->nomC=nomC;};

bool gestion_especeanimal::ajouter_especeanimal()
{
    QSqlQuery query;

    query.prepare("INSERT INTO ESPECESANIMAUX ( IDESPECE , NOMESPECE ) "
                        "VALUES ( :idC, :nomC ) ");

    query.bindValue(":idC",idC);
    query.bindValue(":nomC",nomC);

    return    query.exec();

}
QSqlQueryModel * gestion_especeanimal::afficher_especeanimal()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ESPECESANIMAUX ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Catégorie "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Catégorie"));

    return model;
}
bool gestion_especeanimal::supprimer_especeanimal(QString idC )
{
QSqlQuery query;
QString res= QString(idC);
query.prepare("Delete from  ESPECESANIMAUX where IDESPECE =:idC  ");
query.bindValue(":idC", res);
return    query.exec();
}
bool gestion_especeanimal::modifier_especeanimal(gestion_especeanimal C)
{
    QSqlQuery query;

    query.prepare("UPDATE ESPECESANIMAUX set IDESPECE = :idC , NOMESPECE = :nomC where IDESPECE = :idC ");

    query.bindValue(":idC",C.get_idC());
    query.bindValue(":nomC",C.get_nomC());

    return    query.exec();
}
// heethiiiiiiiiiiiiiiiiiiiiiiiiiiiii hiyaaaaaaaaaaaaaaaa  il refreche il combobox
QSqlQueryModel * gestion_especeanimal::afficher_Clist()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select IDESPECE from ESPECESANIMAUX ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Catégorie "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Catégorie"));
    return model;
}
bool gestion_especeanimal::verif_idC(QString idC)
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
bool gestion_especeanimal::verif_vide(QString a)
{

    bool test=true;

    if(a.length()==0){
       test=false;

    }
    return  test;
}
bool gestion_especeanimal::verif_Nom(QString nomC)
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
QSqlQueryModel *  gestion_especeanimal::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}
