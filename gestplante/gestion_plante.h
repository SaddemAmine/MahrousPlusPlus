#ifndef GESTION_PLANTE_H
#define GESTION_PLANTE_H

#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"


class gestion_plante
{
public:
    gestion_plante();

    gestion_plante(QString,QString,int,QString,QString,QString);
    QString get_idP();
    QString get_secteur();

    int get_quant();
    QString get_etat();
    QString get_idC();
    QString get_image();

    void set_idP(QString);
    void set_secteur(QString);

    void set_quant(int);
    void set_etat(QString);
    void set_idC(QString);
    void set_image(QString);

    bool ajouter_plante();
    QSqlQueryModel * afficher_plante();
    bool supprimer_plante(QString);
    bool modifier_plante(gestion_plante);
    QSqlQueryModel * afficher_plist();
    QSqlQueryModel *  rechercher(QSqlQuery );
    //QSqlQueryModel * afficher_CINlist();

    bool verif_id(QString);
    bool verif_secteur(QString);


private:
    QString idP,secteur,etat,idC,image;
    int quant;

};

#endif // GESTION_PLANTE_H
