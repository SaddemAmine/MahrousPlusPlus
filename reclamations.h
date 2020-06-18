#ifndef RECLAMATIONS_H
#define RECLAMATIONS_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class reclamations
{
public:
    reclamations();
    bool ajoutreclamation(QString, QString, QString);
    bool updatereclamation(QString, QString, int);
    QSqlQueryModel * loadreclamation(QString);
    QSqlQueryModel * preplist();
};

#endif // RECLAMATIONS_H
