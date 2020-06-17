#ifndef GESTION_ESPECEANIMAL_H
#define GESTION_ESPECEANIMAL_H
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"

class gestion_especeanimal
{

public:
    gestion_especeanimal();
    gestion_especeanimal(QString,QString);
    QString get_idC();
    QString get_nomC();

    void set_idC(QString);
    void set_nomC(QString);


    bool ajouter_especeanimal();
    QSqlQueryModel * afficher_especeanimal();
    bool supprimer_especeanimal(QString);
    bool modifier_especeanimal(gestion_especeanimal);
     QSqlQueryModel * afficher_Clist();
     bool verif_idC(QString);
       bool verif_Nom(QString );
       bool verif_vide(QString );
     QSqlQueryModel * rechercher(QSqlQuery);
private:
    QString idC,nomC;

};

#endif // GESTION_ESPECEANIMAL_H
