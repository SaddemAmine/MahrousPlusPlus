#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlError>
#include <QSqlQuery>
#include <QMediaPlayer>
#include <QSqlDatabase>
class connexion
{
public:
    connexion();
    bool createconnect();
    QSqlDatabase mydb;
};

#endif // CONNEXION_H
