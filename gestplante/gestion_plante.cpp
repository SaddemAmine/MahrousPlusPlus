#include "gestion_plante.h"

gestion_plante::gestion_plante()
{

}
gestion_plante::gestion_plante(QString idP,QString secteur,int quant,QString etat , QString idC,QString image)
{
    this->idP=idP;
    this->secteur=secteur;

    this->quant=quant;
    this->etat=etat;
    this->idC=idC;
    this->image=image;
}

QString gestion_plante::get_idP(){return  idP;}
QString gestion_plante::get_secteur(){return  secteur;}

int gestion_plante::get_quant(){return quant;}
QString gestion_plante::get_etat(){return etat;}
QString gestion_plante::get_idC(){return idC;}
QString gestion_plante::get_image(){return image;}


void gestion_plante::set_idP(QString idP){this->idP=idP;};
void gestion_plante::set_secteur(QString secteur){this->secteur=secteur;};

void gestion_plante::set_quant(int quant){this->quant=quant;};
void gestion_plante::set_etat(QString etat){this->etat=etat;};
void gestion_plante::set_idC(QString idC){this->idC=idC;};
void gestion_plante::set_image(QString image){this->image=image;};

bool gestion_plante::ajouter_plante()
{
    QSqlQuery query;


    QString res2= QString::number(quant);


    query.prepare("INSERT INTO PLANTES ( IDPLANTE ,  SECTEUR , QUANTITE, ETAT ,  IDCATEGORIEPLANTE , IMG ) "
                        "VALUES (:idP, :secteur , :quant ,:etat , :idC , :image )");

    query.bindValue(":idP", idP);
    query.bindValue(":secteur", secteur);
    query.bindValue(":quant", quant);
    query.bindValue(":etat", etat);
    query.bindValue(":idC", idC);
    query.bindValue(":image",image);

    return    query.exec();

}

QSqlQueryModel * gestion_plante::afficher_plante()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from  PLANTES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDp "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Secteur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("IdCat"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));

    return model;
}

bool gestion_plante::supprimer_plante(QString idP )
{
QSqlQuery query;
QString res= QString(idP);
query.prepare("Delete from PLANTES where IDPLANTE =:idP ;");
query.bindValue(":idP", res);
return    query.exec();
}
bool gestion_plante::modifier_plante(gestion_plante P)
{
    QSqlQuery query;
    query.prepare("UPDATE PLANTES set IDPLANTE=:idP , SECTEUR=:secteur , QUANTITE=:quant , ETAT=:etat , IDCATEGORIEPLANTE=:idC , IMG = :image  where IDPLANTE=:idP ");
    query.bindValue(":idP",P.get_idP());
    query.bindValue(":secteur",P.get_secteur());

    query.bindValue(":quant",P.get_quant());
    query.bindValue(":etat",P.get_etat());
    query.bindValue(":idC",P.get_idC());
    query.bindValue(":image",P.get_image());

    return    query.exec();
}

QSqlQueryModel * gestion_plante::afficher_plist()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select IDPLANTE from PLANTES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Matériel "));

        return model;
}


bool gestion_plante::verif_id(QString idP){
   bool test=true;
   int i;
   if(idP.length()==0){
      test=false;
      return  test;
   }else{
       for(i=0;i<idP.length();i++){
           if(!((idP[i]>='0')&&(idP[i]<='9'))){
               test=false;
               return  test;
       }
       }
   }
return test;}
bool gestion_plante::verif_secteur(QString secteur){
    bool test=true;
    int i;
    if(secteur.length()>5){
       test=false;
       return  test;
    }else{
        for(i=0;i<secteur.length();i++){
            if(!(((secteur[i]>='A')&&(secteur[i]<='Z'))||((secteur[i]>='a')&&(secteur[i]<='z')))){
                test=false;
                return  test;

        }
    }
  }
    return  test;
}

QSqlQueryModel *  gestion_plante::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}
/*QSqlQueryModel * gestion_plante::afficher_CINlist()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select CIN from personnels");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin "));

        return model;
}*/

