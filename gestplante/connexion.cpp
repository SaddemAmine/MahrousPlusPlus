#include "connexion.h"
#include <QSqlError>
#include <QMediaPlayer>
connexion::connexion()
{

}




bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("wael");//inserer nom de l'utilisateur
db.setPassword("esprit20");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

