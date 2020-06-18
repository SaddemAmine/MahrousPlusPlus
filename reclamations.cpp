#include "reclamations.h"
#include <QDebug>
reclamations::reclamations()
{

}


bool reclamations::ajoutreclamation(QString cin, QString obj, QString msg){
    QSqlQuery * qry = new QSqlQuery();
    qry->prepare("insert into reclamations values (null , :cin , :message , 0 , :obj , null);");
    qry->bindValue(":cin",cin);
    qry->bindValue(":obj",obj);
    qry->bindValue(":message",msg);
    return qry->exec();
}

QSqlQueryModel * reclamations::preplist(){
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    qry->prepare("select objet||', '||nompersonnel||' '||prenompersonnel||', '||reclamations.cin, idreclamation from reclamations, personnels where reclamations.cin = personnels.cin and etat = 0;");
    qry->exec();
    model->setQuery(*qry);
    return model;
    //qDebug() << model->data(model->index(0,1));
}

bool reclamations::updatereclamation(QString whereClause, QString comm, int etat){
    QSqlQuery * qry = new QSqlQuery();
    qry->prepare("update reclamations set commentaire = :commentaire , etat = :etat where idreclamation = "+whereClause+";");
    qry->bindValue(":commentaire",comm);
    qry->bindValue(":etat",etat);
    return qry->exec();
}

QSqlQueryModel * reclamations::loadreclamation(QString whereClause){
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    qDebug () << whereClause ;
    qry->prepare("select message, commentaire from reclamations where idreclamation = "+whereClause+";");

    qry->exec();
    model->setQuery(*qry);
    return model;
}
