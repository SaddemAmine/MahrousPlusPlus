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

rh_personnels_ops::rh_personnels_ops(QString cin, QString nom, QString prenom, QString adresse, QString dateE, QString idFonction, QString password, QString age, QString image){
    this->cin = cin;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->dateE = dateE;
    this->idFonction = idFonction;
    this->image = image;
    this->age = age;
    this->password = password;
}

bool rh_personnels_ops::ajouterPersonnel(){
    QSqlQuery query;
    query.prepare("insert into personnels values (:cin , :nom , :prenom , :adresse , TO_DATE( :dateE ,'DD/MM/YY') , :idFonction , :password , :age , :image );");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":dateE",dateE);
    query.bindValue(":idFonction",idFonction);
    query.bindValue(":password",password);
    query.bindValue(":age",age);
    query.bindValue(":image",image);
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
            password = query.value(6).toString();
            age = query.value(7).toString();
            image = query.value(8).toString();
        }
    }
    //qDebug() << idFonction << " " << cin << " " <<val;
}

bool rh_personnels_ops::modifPersonnel(){
    QSqlQuery query;
    query.prepare("update personnels set nompersonnel = :nom , prenompersonnel = :prenom , adresse = :adresse , dateembauche =(select sysdate from dual) , idfonction = :idFonction , password = :password , age = :age , image = :image where cin = :cin");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    //query.bindValue(":dateE",dateE);
    query.bindValue(":idFonction",idFonction);
    query.bindValue(":password",password);
    query.bindValue(":age",age);
    query.bindValue(":image",image);
    return query.exec();
}

bool rh_personnels_ops::suppPersonnel(){
    QSqlQuery query;
    query.prepare("delete from personnels where cin = :cin");
    query.bindValue(":cin",cin);
    return query.exec();
}
QSqlQueryModel * rh_personnels_ops::trie_NOMCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY NOMPERSONNEL ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel * rh_personnels_ops::trie_NOMDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY NOMPERSONNEL desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel * rh_personnels_ops::trie_cinCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY cin ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel * rh_personnels_ops::trie_cinDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY cin desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel * rh_personnels_ops::trie_PRENOMCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY PRENOMPERSONNEL ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel * rh_personnels_ops::trie_PRENOMDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY PRENOMPERSONNEL desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel * rh_personnels_ops::trie_adresseCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY ADRESSE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel * rh_personnels_ops::trie_adresseDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY ADRESSE desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}

QSqlQueryModel * rh_personnels_ops::trie_ageCroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY AGE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel * rh_personnels_ops::trie_ageDecroissant()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnels ORDER BY AGE desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));
    return model;
}
QSqlQueryModel *  rh_personnels_ops::rechercher(QString q)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("select * from personnels  where cin like '%"+q+"%' OR nompersonnel like '%"+q+"%' OR prenompersonnel like '%"+q+"%' or DATEEMBAUCHE like '%"+q+"%' or IDFONCTION like '%"+q+"%' or PASSWORD like '%"+q+"%' or AGE like '%"+q+"%' or ADRESSE like '%"+q+"%' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFONCTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("IMAGE"));

    return (model);
}
QSqlQuery  rh_personnels_ops::selectpersonnel()
{

    QSqlQuery qry ;

  qry.prepare("select * from PERSONNELS order by  CIN  ");
    return qry;
}
