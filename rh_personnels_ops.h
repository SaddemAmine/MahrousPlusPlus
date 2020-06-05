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
public:
    rh_personnels_ops();
    rh_personnels_ops(QString,QString,QString,QString,QString,QString);
    QString getCin(){ return cin; };
    QString getNom(){ return nom; };
    QString getPrenom(){ return prenom; };
    QString getAdresse(){ return adresse; };
    QString getDateE(){ return dateE; };
    QString getIdFonction(){ return idFonction; };
    bool ajouterPersonnel();
    bool modifPersonnel();
    bool suppPersonnel();
    QSqlQueryModel * afficherPersonnels();
    void chargerPersonnel(QString);
};

#endif // RH_PERSONNELS_OPS_H
