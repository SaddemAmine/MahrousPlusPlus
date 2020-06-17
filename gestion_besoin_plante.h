#ifndef GESTION_BESOIN_PLANTE_H
#define GESTION_BESOIN_PLANTE_H
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"


class gestion_besoin_plante
{
public:
   gestion_besoin_plante();
    gestion_besoin_plante(QString,int,QString);
    QString get_idB();
    int get_ep();
     QString get_np();

    void set_idB(QString);
    void set_ep(int);
    void set_np(QString);


    bool ajouter_besoin_plante();
    QSqlQueryModel * afficher_besoin_plante();
    bool supprimer_besoin_plante(QString);
    bool modifier_besoin_plante(gestion_besoin_plante);

     bool verif_idB(QString);
     QSqlQueryModel * rechercher(QString);
     QSqlQuery tableclicked(QString a);
     QSqlQueryModel *afficher_idCroissant();
     QSqlQueryModel *afficher_idDecroissant();
     QSqlQueryModel *afficher_EauCroissant();
     QSqlQueryModel *afficher_EauDecroissant();
     QSqlQueryModel *afficher_NutCroissant();
     QSqlQueryModel *afficher_NutDecroissant();
     QSqlQuery selectbesoinplante();
private:
    QString idB,np;
    int ep;


};

#endif // GESTION_BESOIN_PLANTE_H
