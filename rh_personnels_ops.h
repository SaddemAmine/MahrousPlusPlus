#ifndef RH_PERSONNELS_OPS_H
#define RH_PERSONNELS_OPS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class rh_personnels_ops{
    QString cin;
    QString nom;
    QString prenom;
    QString adresse;
    QString dateE;
    QString idFonction;
    QString password;
    QString age;
    QString image;
public:
    rh_personnels_ops();
    rh_personnels_ops(QString,QString,QString,QString,QString,QString,QString,QString,QString);
    QString getCin(){ return cin; };
    QString getNom(){ return nom; };
    QString getPrenom(){ return prenom; };
    QString getAdresse(){ return adresse; };
    QString getDateE(){ return dateE; };
    QString getIdFonction(){ return idFonction; };
    QString getage(){return age ;};
    QString getimage(){return image;};
    QString getpassword() {return password;};
    bool ajouterPersonnel();
    bool modifPersonnel();
    bool suppPersonnel();
    QSqlQueryModel * afficherPersonnels();
    void chargerPersonnel(QString);
    QSqlQueryModel *trie_cinCroissant();
    QSqlQueryModel *trie_cinDecroissant();
    QSqlQueryModel *trie_NOMCroissant();
    QSqlQueryModel *trie_NOMDecroissant();
    QSqlQueryModel *trie_PRENOMCroissant();
    QSqlQueryModel *trie_PRENOMDecroissant();
    QSqlQueryModel *trie_adresseCroissant();
    QSqlQueryModel *trie_adresseDecroissant();
    QSqlQueryModel *trie_ageCroissant();
    QSqlQueryModel *trie_ageDecroissant();
    QSqlQueryModel *rechercher(QString q);
    QSqlQuery selectpersonnel();
};

#endif // RH_PERSONNELS_OPS_H
