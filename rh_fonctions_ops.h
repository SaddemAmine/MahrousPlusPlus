#ifndef RH_FONCTIONS_OPS_H
#define RH_FONCTIONS_OPS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class rh_fonctions_ops{
    QString idFonction;
    QString nomFonction;
    int salaire;
    QString description;
public:
    rh_fonctions_ops();
    rh_fonctions_ops(QString,QString,int,QString);
    QString getId();
    QString getNom();
    int getSalaire();
    QString getDescription();
    void setId(QString);
    void setNom(QString);
    void setSalaire(int);
    void setDescription(QString);
    bool ajouterFonction();
    bool modifFonction();
    bool suppFonction();
    QSqlQueryModel * afficherFonctions(int);
    QSqlQueryModel *afficher_idCroissant();
    QSqlQueryModel *afficher_idDecroissant();
    QSqlQueryModel *afficher_SalaireCroissant();
    QSqlQueryModel *afficher_SalaireDecroissant();
    QSqlQueryModel *afficher_NomCroissant();
    QSqlQueryModel *afficher_NomDecroissant();
    QSqlQueryModel *rechercher(QString q);
    QSqlQuery tableclicked(QString a);
    QSqlQuery selectfonction();
};

#endif // RH_FONCTIONS_OPS_H
