#ifndef GESTION_PRODUIT_PLANTE_H
#define GESTION_PRODUIT_PLANTE_H

#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
class gestion_produit_plante
{
public:
      gestion_produit_plante();
    gestion_produit_plante(int,QString,QString ,int);

    int get_idPP();
   QString get_idCP();
    int get_PrixP();
    QString get_PP();

    void set_idPP(int);
    void set_idCP(QString);
    void set_PrixP(int);
    void set_PP(QString );

    bool ajouter_produit_plante();
    QSqlQueryModel *afficher_produit_plante();
    bool modifier_produit_palnte(gestion_produit_plante );
    bool supprimer_produit_plante(int);
    QSqlQueryModel *afficher_pplist();
    bool verif_id(int);

    QSqlQueryModel *afficher_idCroissant();
    QSqlQueryModel *afficher_idDecroissant();
    QSqlQueryModel *afficher_PrixDecroissant();
    QSqlQueryModel *afficher_PrixCroissant();
    QSqlQueryModel *rechercher(QString q);
    QSqlQuery tableclicked(QString a);
    QSqlQuery selectpeoduitplante();
private:
    QString  PRODUITPLANTE ,IDCATEGORIEPLANTE   ;
    int  IDPRODUCTIONPLANTE,PRIXPRODUITPLANTE;
};

#endif // GESTION_PRODUIT_PLANTE_H
