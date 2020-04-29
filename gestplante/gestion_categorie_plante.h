#ifndef GESTION_CATEGORIE_PLANTE_H
#define GESTION_CATEGORIE_PLANTE_H
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"

class gestion_categorie_plante
{

public:
    gestion_categorie_plante();
    gestion_categorie_plante(QString,QString);
    QString get_idC();
    QString get_nomC();

    void set_idC(QString);
    void set_nomC(QString);


    bool ajouter_Categorie();
    QSqlQueryModel * afficher_Categorie();
    bool supprimer_Categorie(QString);
    bool modifier_Categorie(gestion_categorie_plante);
     QSqlQueryModel * afficher_Clist();
     bool verif_idC(QString);
     bool verif_Nom(QString );
     bool verif_vide(QString );
     QSqlQueryModel * rechercher(QSqlQuery);


private:
    QString idC,nomC;

};

#endif // GESTION_CATEGORIE_PLANTE_H

