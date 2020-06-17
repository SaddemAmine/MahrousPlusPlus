
#include "gestion_produit_plante.h"
gestion_produit_plante::gestion_produit_plante()
{

}

gestion_produit_plante::gestion_produit_plante(int  IDPRODUCTIONPLANTE, QString IDCATEGORIEPLANTE,QString PRODUITPLANTE,int  PRIXPRODUITPLANTE )
{
    this-> IDPRODUCTIONPLANTE= IDPRODUCTIONPLANTE;
    this-> IDCATEGORIEPLANTE = IDCATEGORIEPLANTE ;

    this-> PRODUITPLANTE = PRODUITPLANTE ;
    this->PRIXPRODUITPLANTE=PRIXPRODUITPLANTE;

}

int gestion_produit_plante::get_idPP(){return  IDPRODUCTIONPLANTE;}
QString gestion_produit_plante::get_idCP(){return  IDCATEGORIEPLANTE;}
int gestion_produit_plante::get_PrixP(){return PRIXPRODUITPLANTE;}
QString gestion_produit_plante::get_PP(){return PRODUITPLANTE;}


void gestion_produit_plante::set_idPP(int IDPRODUCTIONPLANTE){this->IDPRODUCTIONPLANTE=IDPRODUCTIONPLANTE;};
void gestion_produit_plante::set_idCP(QString IDCATEGORIEPLANTE){this->IDCATEGORIEPLANTE=IDCATEGORIEPLANTE;};
void gestion_produit_plante::set_PrixP(int PRIXPRODUITPLANTE){this->PRIXPRODUITPLANTE=PRIXPRODUITPLANTE;};
void gestion_produit_plante::set_PP(QString PRODUITPLANTE){this->PRODUITPLANTE=PRODUITPLANTE;};


bool gestion_produit_plante::ajouter_produit_plante()
{
    QSqlQuery query;


    QString res1= QString::number(IDPRODUCTIONPLANTE);
 //QString res2= QString::number(IDCATEGORIEPLANTE);
 QString res3= QString::number(PRIXPRODUITPLANTE);


    query.prepare("INSERT INTO productionplante (IDPRODUCTIONPLANTE,IDCATEGORIEPLANTE, PRODUITPLANTE,PRIXPRODUITPLANTE ) "
                        "VALUES ( :IDPRODUCTIONPLANTE , :IDCATEGORIEPLANTE , :PRODUITPLANTE , :PRIXPRODUITPLANTE )");

    query.bindValue(":IDPRODUCTIONPLANTE",IDPRODUCTIONPLANTE);
    query.bindValue(":IDCATEGORIEPLANTE", IDCATEGORIEPLANTE);
    query.bindValue(":PRODUITPLANTE", PRODUITPLANTE);
    query.bindValue(":PRIXPRODUITPLANTE", PRIXPRODUITPLANTE);

    return    query.exec();

}

QSqlQueryModel * gestion_produit_plante::afficher_produit_plante()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from  productionplante");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPRODUCTIONPLANTE "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDCATEGORIEPLANTE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRODUITPLANTE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr(" PRIXPRODUITPLANTE"));

    return model;
}

bool gestion_produit_plante::supprimer_produit_plante(int IDPRODUCTIONPLANTE )
{
QSqlQuery query;
int res= int(IDPRODUCTIONPLANTE);
query.prepare("Delete from PRODUCTIONPLANTE where IDPRODUCTIONPLANTE =:IDPRODUCTIONPLANTE ;");
query.bindValue(":IDPRODUCTIONPLANTE", res);
return    query.exec();
}
bool gestion_produit_plante::modifier_produit_palnte(gestion_produit_plante P)
{
    QSqlQuery query;
    query.prepare("UPDATE PRODUCTIONPLANTE  set IDPRODUCTIONPLANTE =:IDPRODUCTIONPLANTE, IDCATEGORIEPLANTE=:IDCATEGORIEPLANTE , PRODUITPLANTE=:PRODUITPLANTE ,PRIXPRODUITPLANTE=:PRIXPRODUITPLANTE  where IDPRODUCTIONPLANTE=:IDPRODUCTIONPLANTE ");
    query.bindValue(":IDPRODUCTIONPLANTE",P.get_idPP());
    query.bindValue(":IDCATEGORIEPLANTE",P.get_idCP());
    query.bindValue(":PRODUITPLANTE",P.get_PP());
    query.bindValue(":PRIXPRODUITPLANTE",P.get_PrixP());

    return    query.exec();
}

QSqlQueryModel * gestion_produit_plante::afficher_pplist()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select IDCATEGORIEPLANTE from CATEGORIESPLANTES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDc "));

        return model;
}


bool gestion_produit_plante::verif_id(int IDPRODUCTIONPLANTE){
   bool test=true;
 //  int i;
   if(IDPRODUCTIONPLANTE==0){
      test=false;
      return  test;
   }else{
       /*for(i=0;i<idB;i++){
           if(!((idB[i]>='0')&&(idB[i]<='9'))){
               test=false;*/
               return  test;
       //}
       }
  // }
return test;}


QSqlQueryModel *  gestion_produit_plante::rechercher(QString q)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("select * from PRODUCTIONPLANTE where IDPRODUCTIONPLANTE like '"+q+"' OR PRIXPRODUITPLANTE like '"+q+"' OR IDCATEGORIEPLANTE like '"+q+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPRODUCTIONPLANTE "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDCATEGORIEPLANTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRODUITPLANTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" PRIXPRODUITPLANTE"));

    return (model);
}

QSqlQueryModel * gestion_produit_plante::afficher_idCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUCTIONPLANTE ORDER BY IDPRODUCTIONPLANTE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPRODUCTIONPLANTE "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDCATEGORIEPLANTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRODUITPLANTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" PRIXPRODUITPLANTE"));

    return model;
}
QSqlQueryModel * gestion_produit_plante::afficher_idDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUCTIONPLANTE ORDER BY IDPRODUCTIONPLANTE desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPRODUCTIONPLANTE "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDCATEGORIEPLANTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRODUITPLANTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" PRIXPRODUITPLANTE"));

    return model;
}
QSqlQueryModel * gestion_produit_plante::afficher_PrixCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUCTIONPLANTE ORDER BY PRIXPRODUITPLANTE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPRODUCTIONPLANTE "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDCATEGORIEPLANTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRODUITPLANTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" PRIXPRODUITPLANTE"));

    return model;
}
QSqlQueryModel * gestion_produit_plante::afficher_PrixDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUCTIONPLANTE ORDER BY PRIXPRODUITPLANTE desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPRODUCTIONPLANTE "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDCATEGORIEPLANTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRODUITPLANTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" PRIXPRODUITPLANTE"));

    return model;
}
QSqlQuery  gestion_produit_plante::tableclicked(QString a)
{

    QSqlQuery qry ;

    qry.prepare("Select * from PRODUCTIONPLANTE where IDPRODUCTIONPLANTE='"+a+"' ");
    return qry;
}
QSqlQuery  gestion_produit_plante::selectpeoduitplante()
{

    QSqlQuery qry ;

  qry.prepare("select * from PRODUCTIONPLANTE order by IDPRODUCTIONPLANTE ");
    return qry;
}
